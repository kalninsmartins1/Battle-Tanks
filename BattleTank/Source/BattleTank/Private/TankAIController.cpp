// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "TankPlayerController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ATank* AITank = GetAITank();
	ATank* PlayerTank = GetPlayerTank();
	if (AITank != nullptr && PlayerTank != nullptr)
	{
		AITank->AimAt(PlayerTank->GetActorLocation());
		AITank->Fire();
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
