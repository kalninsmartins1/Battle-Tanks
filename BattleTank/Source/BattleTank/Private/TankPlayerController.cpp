// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"


ATank* ATankPlayerController::GetPlayerTank() const 
{
	return Cast<ATank>(GetPawn());
}

