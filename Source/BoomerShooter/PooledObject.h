// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PooledObject.generated.h"
#include "PooledObject.h"
#include "Delegates/Delegate.h"
#include "Delegates/DelegateCombinations.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPooledObjectDespawn, APooledObject*, PoolActor);

UCLASS()
class BOOMERSHOOTER_API APooledObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APooledObject();

	FOnPooledObjectDespawn OnPooledObjectDespawn;

	UFUNCTION(BlueprintCallable, Category = "Pooled Object")
		void Deactivate();

	void SetActive(bool IsActive);
	void SetLifeSpan(float LifeSpan);
	void SetPoolIndex(int Index);

	bool IsActive() const;
	int GetPoolIndex() const;

protected:
	
	bool Active;
	float LifeSpan = 0.0f;
	int PoolIndex;

	FTimerHandle LifeSpanTimer;
};
