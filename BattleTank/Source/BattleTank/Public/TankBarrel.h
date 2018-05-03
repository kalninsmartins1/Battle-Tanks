// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hideCategories = (Collision))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UTankBarrel();

public:
	// Relative degrees from -1 to 1
	void	Elevate(float RelativeDegreesPerSecond);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationAngle;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationAngle;
};
