// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hideCategories = (Collision))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	// Set tank trottle between -1 and 1
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetTrottle(float value);

private:
	UTankTrack();

private:
	// Move force in Newtons
	float MaxTankMoveForce;
};
