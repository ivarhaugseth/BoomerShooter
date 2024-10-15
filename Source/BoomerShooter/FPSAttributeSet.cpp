// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSAttributeSet.h"

UFPSAttributeSet::UFPSAttributeSet()
{
}

void UFPSAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
}

bool UFPSAttributeSet::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
	float AbsoluteMagnitude = FMath::Abs(Data.EvaluatedData.Magnitude);

	if (Data.EvaluatedData.Magnitude > 0)
	{
		if (Data.EvaluatedData.Attribute == GetArmorAttribute() && GetArmor() + AbsoluteMagnitude >= 100)
		{
			SetArmor(100);
			return false;
		}
		if (Data.EvaluatedData.Attribute == GetHealthAttribute() && GetHealth() + AbsoluteMagnitude >= 100)
		{
			SetHealth(100);
			return false;
		}
	}
	else
	{
		// Case where the damage is greater than the armor value and so the armor is destroyed and the remaining damage is applied to the health
		if (Data.EvaluatedData.Attribute == GetArmorAttribute() && AbsoluteMagnitude > GetArmor())
		{
			Health.SetCurrentValue(Health.GetCurrentValue() - (AbsoluteMagnitude - GetArmor()));
		}
	}

	return true;
}
