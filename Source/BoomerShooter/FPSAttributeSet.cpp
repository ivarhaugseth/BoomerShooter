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
	float ArmorDamage = FMath::Abs(Data.EvaluatedData.Magnitude);

	// Case where the damage is greater than the armor value and so the armor is destroyed and the remaining damage is applied to the health
	if (Data.EvaluatedData.Attribute == GetArmorAttribute() && ArmorDamage > GetArmor() && Data.EvaluatedData.Magnitude < 0)
	{
		Health.SetCurrentValue(Health.GetCurrentValue() - (ArmorDamage - GetArmor()));
	}

	return true;
}
