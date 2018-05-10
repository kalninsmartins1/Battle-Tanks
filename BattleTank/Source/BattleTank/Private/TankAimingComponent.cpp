// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankTurret.h"

const FName UTankAimingComponent::ProjectileSocketName = "Projectile";

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankAimingComponent::GetShootingStartLocation(FVector& OutStartLocation) const
{
	OutStartLocation = BarrelComponent->GetSocketLocation(ProjectileSocketName);
}

void UTankAimingComponent::GetShootingStartRotation(FRotator& OutStartRotation) const
{
	OutStartRotation = BarrelComponent->GetSocketRotation(ProjectileSocketName);
}

void UTankAimingComponent::SetBarrelComponent(UTankBarrel* BarrelComponent)
{
	this->BarrelComponent = BarrelComponent;
}

void UTankAimingComponent::SetTurretComponent(UTankTurret* TurretComponent)
{
	this->TurretComponent = TurretComponent;
}

void UTankAimingComponent::MoveBarrelTowards(const FVector& AimDirection)
{
	// Get angle between shoot direction and barrel current direction
	const FRotator& BarrelRotation = BarrelComponent->GetForwardVector().Rotation();
	const FRotator& AimDirectionRotation = AimDirection.Rotation();
	FRotator DeltaRotation = AimDirectionRotation - BarrelRotation;

	// Rotate the barrel by the found angle	
	BarrelComponent->Elevate(DeltaRotation.Pitch);
	TurretComponent->Rotate(DeltaRotation.Yaw);
}

void UTankAimingComponent::AimAt(const FVector& WorldLocation, float ShootSpeed)
{	
	if (BarrelComponent != nullptr)
	{
		FVector StartLocation;
		GetShootingStartLocation(StartLocation);

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

