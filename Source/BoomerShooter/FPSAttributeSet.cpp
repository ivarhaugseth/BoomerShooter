// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSAttributeSet.h"
#include "FPSCharacter.h"

UFPSAttributeSet::UFPSAttributeSet()
{
}

void UFPSAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	AFPSCharacter* Character = Cast<AFPSCharacter>(GetOwningActor());

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0, Character->MaxHealth);
	}
	else if (Attribute == GetArmorAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0, Character->MaxArmor);
	}
	else if (Attribute == GetShotgunAmmoAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0, Character->MaxShotgunAmmo);
	}
	else if (Attribute == GetPistolAmmoAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0, Character->MaxPistolAmmo);
	}
}

bool UFPSAttributeSet::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
	float AbsoluteMagnitude = FMath::Abs(Data.EvaluatedData.Magnitude);

	AFPSCharacter* Character = Cast<AFPSCharacter>(GetOwningActor());

	if (Data.EvaluatedData.Magnitude > 0)
	{
		if (Data.EvaluatedData.Attribute == GetArmorAttribute() && GetArmor() + AbsoluteMagnitude >= Character->MaxArmor)
		{
			SetArmor(FMath::Clamp(GetArmor(), 0.0f, Character->MaxArmor));
			return false;
		}
		else if (Data.EvaluatedData.Attribute == GetHealthAttribute() && GetHealth() + AbsoluteMagnitude >= Character->MaxHealth)
		{
			SetHealth(Character->MaxHealth);
			return false;
		}
		else if (Data.EvaluatedData.Attribute == GetShotgunAmmoAttribute() && GetShotgunAmmo() + AbsoluteMagnitude >= Character->MaxShotgunAmmo)
		{
			SetShotgunAmmo(Character->MaxShotgunAmmo);
			return false;
		}
		else if (Data.EvaluatedData.Attribute == GetPistolAmmoAttribute() && GetPistolAmmo() + AbsoluteMagnitude >= Character->MaxPistolAmmo)
		{
			SetPistolAmmo(Character->MaxPistolAmmo);
			return false;
		}
		else if (Data.EvaluatedData.Attribute == GetGrenadeAmmoAttribute() && GetGrenadeAmmo() + AbsoluteMagnitude >= Character->MaxGrenadeAmmo)
		{
			SetGrenadeAmmo(Character->MaxGrenadeAmmo);
			return false;
		}
	}
	else if (Data.EvaluatedData.Magnitude < 0)
	{
		// Case where the damage is greater than the armor value and so the armor is destroyed and the remaining damage is applied to the health
		if (Data.EvaluatedData.Attribute == GetArmorAttribute() && AbsoluteMagnitude > GetArmor())
		{
			float RemainingDamage = AbsoluteMagnitude - GetArmor();
			SetArmor(0);
			Health.SetCurrentValue(Health.GetCurrentValue() - RemainingDamage);
		}
	}

	return true;
}

void UFPSAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute == GetHealthAttribute() && GetHealth() < 0)
	{
		SetHealth(0);
	}
	else if (Data.EvaluatedData.Attribute == GetArmorAttribute() && GetArmor() < 0)
	{
		SetArmor(0);
	}
	else if (Data.EvaluatedData.Attribute == GetShotgunAmmoAttribute() && GetShotgunAmmo() < 0)
	{
		SetShotgunAmmo(0);
	}
	else if (Data.EvaluatedData.Attribute == GetPistolAmmoAttribute() && GetPistolAmmo() < 0)
	{
		SetPistolAmmo(0);
	}
	else if (Data.EvaluatedData.Attribute == GetGrenadeAmmoAttribute() && GetGrenadeAmmo() < 0)
	{
		SetGrenadeAmmo(0);
	}
}
