// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


UTankBarrel::UTankBarrel()
	: MaxDegreesPerSecond(20.0f)
	, MaxElevationAngle(20.0f)
	, MinElevationAngle(0.0f)
{

}

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	UE_LOG(LogTemp, Warning, TEXT("Elevating Barrel at %f speed"), DegreesPerSecond);
}
