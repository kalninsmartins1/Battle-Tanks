// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:	
	ATank* GetPlayerTank() const;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	bool		 GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool		 GetMaxShootLocation(FVector& OutMaxShootLocation) const;

	// Start moving tank barrel so that a shot would hit world where crosshair intersects it
	void		 AimTowardsCrosshair();
};
