// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"
#include "Runtime/Engine/Classes/Engine/World.h"



ATankPlayerController::ATankPlayerController()
	: CrosshairNormalizedLocationX(0.5f)
	, CrosshairNormalizedLocationY(0.3333f)
{

}

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

void ATankPlayerController::GetCrosshairScreenPosition(FVector2D& OutScreenPosition) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	
	OutScreenPosition = FVector2D(ViewportSizeX * CrosshairNormalizedLocationX,
		ViewportSizeY * CrosshairNormalizedLocationY);
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{	
	// Find the crosshair position
	FVector2D CrossHairScreenLocation;
	GetCrosshairScreenPosition(CrossHairScreenLocation);

	// "De-project" the screen position of the crosshair to a world direction
	FVector LookDirection;
	GetLookDirection(CrossHairScreenLocation, LookDirection);

	// Line-trace along that lok direction, and see waht we hit ()up to max range
	FVector MaxShootLocation;
	GetMaxShootLocation(LookDirection, MaxShootLocation);
	
	FHitResult Hit;
	GetWorld()->LineTraceSingleByChannel(
		Hit,
		GetPlayerTank()->GetActorLocation(),
		MaxShootLocation, 
		ECC_Destructible
		);

	OutHitLocation = Hit.Location;

	return true;//Hit.Actor != nullptr;
}

bool ATankPlayerController::GetMaxShootLocation(const FVector& LookDirection, FVector& OutMaxShootLocation) const
{
	// Get tank shoot range
	float ShootRange = 0;
	ATank* Tank = GetPlayerTank();
	if (Tank != nullptr)
	{
		ShootRange = Tank->GetShootRange();
	}
	OutMaxShootLocation = GetPlayerTank()->GetActorLocation() + LookDirection * ShootRange;

	return Tank != nullptr;
}

bool ATankPlayerController::GetLookDirection(const FVector2D& ScreenLocation, FVector& OutLookDirection) const
{
	FVector CameraWorldLocation; // Not used
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y,
		CameraWorldLocation, 
		OutLookDirection); // From camera to crosshair
}

ATank* ATankPlayerController::GetPlayerTank() const 
{
	return Cast<ATank>(GetPawn());
}

