// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"



UTankTurret::UTankTurret()
	:	MaxDegreesPerSecond(15.0f)
{

}

void UTankTurret::Rotate(float RelativeRotationPerSeconds)
{
	RelativeRotationPerSeconds = FMath::Clamp(RelativeRotationPerSeconds, -1.0f, 1.0f);
	float DeltaTime = GetWorld()->GetDeltaSeconds();

	float RelativeDegreesStep = RelativeRotationPerSeconds * MaxDegreesPerSecond * DeltaTime;
	float NewRelativeYaw = RelativeRotation.Yaw + RelativeDegreesStep;
	SetRelativeRotation(FRotator(0.0f, NewRelativeYaw, 0.f));
}
