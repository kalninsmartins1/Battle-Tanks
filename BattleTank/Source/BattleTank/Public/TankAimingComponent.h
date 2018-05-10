// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

public:
	void GetShootingStartLocation(FVector& OutStartLocation) const;
	void GetShootingStartRotation(FRotator& OutStartRotation) const;

	void SetBarrelComponent(UTankBarrel* BarrelComponent);
	void SetTurretComponent(UTankTurret* TurretComponent);

	void AimAt(const FVector& WorldLocation, float ShootSpeed);

private:
	void MoveBarrelTowards(const FVector& AimDirection);

private:
	static const FName ProjectileSocketName;
	UTankBarrel* BarrelComponent;
	UTankTurret* TurretComponent;
};
