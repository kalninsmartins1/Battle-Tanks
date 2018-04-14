// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"
#include "Runtime/Engine/Classes/Engine/World.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();	

	auto Tank = GetPlayerTank();
	if (Tank != nullptr)
	{
		const FString& TankName = Tank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController: Player tank found %s"), *TankName);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController: Player tank not found !"));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (GetPlayerTank() != nullptr)
	{
		// Cast a ray from tanks barrel trough crosshair and check if it hits
		FVector OutHitLocation;

		GetSightRayHitLocation(OutHitLocation);
		UE_LOG(LogTemp, Warning, TEXT("Current hit location: %s"), *OutHitLocation.ToString());		
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{	
	FVector MaxShootLocation;
	GetMaxShootLocation(MaxShootLocation);

	// Perform a line trace
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		Hit,
		GetPlayerTank()->GetActorLocation(),
		MaxShootLocation,
		FCollisionObjectQueryParams(
			ECollisionChannel::ECC_PhysicsBody),
		FCollisionQueryParams(FName(TEXT("")), false, GetPlayerTank()));

	OutHitLocation = Hit.Location;

	return Hit.Actor != nullptr;
}

bool ATankPlayerController::GetMaxShootLocation(FVector& OutMaxShootLocation) const
{
	// Get view point rotation and player location
	FVector OutPlayerLocation;
	FRotator OutViewPointRotation;
	GetPlayerViewPoint(OutPlayerLocation,
		OutViewPointRotation);

	// Get tank shoot range
	float ShootRange = 0;
	ATank* Tank = GetPlayerTank();
	if (Tank != nullptr)
	{
		ShootRange = Tank->GetShootRange();
	}
	OutMaxShootLocation = OutPlayerLocation + OutViewPointRotation.Vector() * ShootRange;

	return Tank != nullptr;
}

ATank* ATankPlayerController::GetPlayerTank() const 
{
	return Cast<ATank>(GetPawn());
}

