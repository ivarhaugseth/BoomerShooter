// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include <GameplayEffectTypes.h>
#include "AbilitySystemInterface.h"
#include "FPSCharacter.generated.h"

/**
 * This class defines the player character
 * It contains the Ability System Component and the Attribute Set for the player character
 */
UCLASS()
class BOOMERSHOOTER_API AFPSCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
		class UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	class UFPSAttributeSet* Attributes;

public:
	// Sets default values for this character's properties
	AFPSCharacter();

	// Overriden from IAbilitySystemInterface
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this character's properties
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "FPS")
		TSubclassOf<class UGameplayEffect> DefaultAttributeEffect;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "FPS")
		TArray<TSubclassOf<class UGameplayAbility>> DefaultAbilities;

};
