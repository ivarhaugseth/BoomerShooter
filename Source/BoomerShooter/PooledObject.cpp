// Fill out your copyright notice in the Description page of Project Settings.


#include "PooledObject.h"

// Sets default values
APooledObject::APooledObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void APooledObject::SetActive(bool IsActive)
{
}

void APooledObject::SetLifeSpan(float LifeSpan)
{
}

void APooledObject::SetPoolIndex(int Index)
{
}

bool APooledObject::IsActive() const
{
	return false;
}

int APooledObject::GetPoolIndex() const
{
	return 0;
}