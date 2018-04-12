// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "TankPlayerController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* PlayerTank = GetPlayerTank();
	const FString& TankName = GetName();
	if (PlayerTank != nullptr)
	{
		const FString& PlayerTankName = PlayerTank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("TankAIController: AI tank %s has found Player tank %s"), *TankName, *PlayerTankName);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController: AI tank %s did not find Player tank !"), *TankName);
	}
}

ATank* ATankAIController::GetAITank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	ATank* PlayerTank = nullptr;

	auto TankPlayerController = Cast<ATankPlayerController>(GetWorld()->GetFirstPlayerController());
	if (TankPlayerController != nullptr)
	{
		PlayerTank = TankPlayerController->GetPlayerTank();
	}

	return PlayerTank;
}
