// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"


void UTankTurret::Rotate(float RelativeRotationPerSeconds)
{
	float DeltaTime = GetWorld()->GetDeltaSeconds();
	float NewRelativeYaw = RelativeRotation.Yaw + RelativeRotationPerSeconds * DeltaTime;
	SetRelativeRotation(FRotator(0.0f, NewRelativeYaw, 0.f));
}
