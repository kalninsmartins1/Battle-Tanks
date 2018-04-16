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
	ATankPlayerController();

public:	
	ATank* GetPlayerTank() const;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	bool		 GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool		 GetMaxShootLocation(const FVector& LookDirection, FVector& OutMaxShootLocation) const;
	bool		 GetLookDirection(const FVector2D& ScreenLocation, FVector& OutLookDirection) const;
	void		 GetCrosshairScreenPosition(FVector2D& OutScreenPosition) const;

	// Start moving tank barrel so that a shot would hit world where crosshair intersects it
	void		 AimTowardsCrosshair();

private:
	UPROPERTY(EditAnywhere)
	float		CrosshairNormalizedLocationX;

	UPROPERTY(EditAnywhere)
	float		CrosshairNormalizedLocationY;
};
