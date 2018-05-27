// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

UTankTrack::UTankTrack()
	: MaxTankMoveForce(400000)
{

}

void UTankTrack::SetTrottle(float value)
{
	UE_LOG(LogTemp, Warning, TEXT("TankTrack: Trottle %f"), value);

	FVector AppliedForce = GetForwardVector() * MaxTankMoveForce * value;
	FVector ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(AppliedForce, ForceLocation);
}
