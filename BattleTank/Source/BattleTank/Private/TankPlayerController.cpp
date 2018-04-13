// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"


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
	}
}

ATank* ATankPlayerController::GetPlayerTank() const 
{
	return Cast<ATank>(GetPawn());
}

