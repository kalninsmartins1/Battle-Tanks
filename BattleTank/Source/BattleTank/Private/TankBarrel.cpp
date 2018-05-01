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
	float RelativeDegreesStep = RelativeDegreesPerSecond * MaxElevationAngle * DeltaTime;

	// Set the rotation
	float NewElevation = FMath::Clamp(RelativeRotation.Pitch + RelativeDegreesStep, MinElevationAngle, MaxElevationAngle);	
	UE_LOG(LogTemp, Warning, TEXT("TankBarrel: ElevationRelativeDegrees %f !"), DeltaTime, RelativeDegreesStep);
	SetRelativeRotation(FRotator(NewElevation, 0.0f, 0.0f));
}
