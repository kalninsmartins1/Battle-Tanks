// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* AiTank = GetAITank();
	if (AiTank != nullptr)
	{
		const FString& AiTankName = AiTank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("TankAIController: AI Tank found %s"), *AiTankName);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController: AI Tank not found !"));
	}
}

ATank* ATankAIController::GetAITank()
{
	return Cast<ATank>(GetPawn());
}
