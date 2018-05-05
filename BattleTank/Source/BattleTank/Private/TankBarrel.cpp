// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


UTankBarrel::UTankBarrel()
	: MaxDegreesPerSecond(5.0f)
	, MaxElevationAngle(20.0f)
	, MinElevationAngle(0.0f)
{

}

void UTankBarrel::Elevate(float RelativeDegreesPerSecond)
{
	// Clamp relative speed
	RelativeDegreesPerSecond = FMath::Clamp(RelativeDegreesPerSecond, -1.0f, 1.0f);	

	// Get step
	float DeltaTime = GetWorld()->DeltaTimeSeconds;
	float RelativeElevationStep = RelativeDegreesPerSecond * MaxElevationAngle * DeltaTime;	

	// Set the rotation
	float NewRotation = FMath::Clamp(RelativeRotation.Pitch + RelativeElevationStep, MinElevationAngle, MaxElevationAngle);	
	SetRelativeRotation(FRotator(NewRotation, 0.0f, 0.0f));
}
