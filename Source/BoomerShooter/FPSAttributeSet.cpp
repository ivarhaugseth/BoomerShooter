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
	else if (Attribute == GetBulletsAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0, Character->MaxBullets);
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
			SetArmor(Character->MaxArmor);
			return false;
		}
		else if (Data.EvaluatedData.Attribute == GetHealthAttribute() && GetHealth() + AbsoluteMagnitude >= Character->MaxHealth)
		{
			SetHealth(Character->MaxHealth);
			return false;
		}
		else if (Data.EvaluatedData.Attribute == GetBulletsAttribute() && GetBullets() + AbsoluteMagnitude >= Character->MaxBullets)
		{
			SetBullets(Character->MaxBullets);
			return false;
		}
	}
	else if (Data.EvaluatedData.Magnitude < 0)
	{
		// Case where the damage is greater than the armor value and so the armor is destroyed and the remaining damage is applied to the health
		if (Data.EvaluatedData.Attribute == GetArmorAttribute() && AbsoluteMagnitude > GetArmor())
		{
			Health.SetCurrentValue(Health.GetCurrentValue() - (AbsoluteMagnitude - GetArmor()));
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
	else if (Data.EvaluatedData.Attribute == GetBulletsAttribute() && GetBullets() < 0)
	{
		SetBullets(0);
	}
}
