#include "TurretAttributeSet.h"

UTurretAttributeSet::UTurretAttributeSet()
{
	// Initialize default values
	Health.SetBaseValue(40.0f);
	Health.SetCurrentValue(40.0f);

	Armor.SetBaseValue(40.0f);
	Armor.SetCurrentValue(40.0f);
}

void UTurretAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetHealth());
	}
	else if (Attribute == GetArmorAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetArmor());
	}
}

bool UTurretAttributeSet::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute == GetArmorAttribute())
	{
		float CurrentArmor = GetArmor();
		float IncomingDamage = -Data.EvaluatedData.Magnitude; // Damage is negative

		if (IncomingDamage > 0 && CurrentArmor <= 0)
		{
			// Apply all damage to health if armor is already 0
			Data.EvaluatedData.Magnitude = 0; // Cancel damage to Armor
			float CurrentHealth = GetHealth();
			SetHealth(FMath::Clamp(CurrentHealth - IncomingDamage, 0.0f, GetHealth()));
			return true;
		}

		// Handle overflow damage from armor
		if (IncomingDamage > CurrentArmor)
		{
			float OverflowDamage = IncomingDamage - CurrentArmor;

			// Set Armor to 0
			SetArmor(0);

			// Apply the remaining damage to health
			float CurrentHealth = GetHealth();
			SetHealth(FMath::Clamp(CurrentHealth - OverflowDamage, 0.0f, GetHealth()));

			// Cancel further damage to armor
			Data.EvaluatedData.Magnitude = 0;
		}
	}

	return true;
}

void UTurretAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute == GetArmorAttribute())
	{
		if (GetArmor() < 0)
		{
			SetArmor(0);
		}
	}
}
