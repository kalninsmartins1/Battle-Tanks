// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("TankPlayerController: Begin play"));

	auto Tank = GetPlayerTank();
	if (Tank != nullptr)
	{
		const FString& TankName = Tank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController: Tank found %s"), *TankName);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController: Tank not found !"));
	}
}

ATank* ATankPlayerController::GetPlayerTank() const 
{
	return Cast<ATank>(GetPawn());
}

