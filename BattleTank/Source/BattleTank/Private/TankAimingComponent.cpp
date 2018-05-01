// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "TankBarrel.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankAimingComponent::SetBarrelComponent(UTankBarrel* BarrelComponent)
{
	this->BarrelComponent = BarrelComponent;
}

void UTankAimingComponent::MoveBarrelTowards(const FVector& AimDirection)
{
	// Get angle between shoot direction and barrel current direction
	const FRotator& BarrelRotation = BarrelComponent->GetForwardVector().Rotation();
	const FRotator& AimDirectionRotation = AimDirection.Rotation();
	const FRotator& DeltaRotation = AimDirectionRotation - BarrelRotation;

	// Rotate the barrel by the found angle
	BarrelComponent->Elevate(DeltaRotation.Pitch);
}

void UTankAimingComponent::AimAt(const FVector& WorldLocation, float ShootSpeed)
{	
	if (BarrelComponent != nullptr)
	{
		const FVector StartLocation = BarrelComponent->GetSocketLocation(FName("Projectile"));
		
		FVector OutShootDirection;
		float Time = GetWorld()->GetTimeSeconds();
		if (UGameplayStatics::SuggestProjectileVelocity(this, OutShootDirection, StartLocation,
				WorldLocation, ShootSpeed, false, 0.0f, 0.0f,
				ESuggestProjVelocityTraceOption::DoNotTrace)) // Need to provide these default values for function to work properly
		{
			OutShootDirection.Normalize();
			MoveBarrelTowards(OutShootDirection);
		}
	}
}

