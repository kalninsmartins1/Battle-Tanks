// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;
class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

public:	
	float		 GetShootRange() const;
	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void		 SetBarrelComponent(UTankBarrel* BarrelComponent);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void		 SetTurretComponent(UTankTurret* TurretComponent);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void		 Fire();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void		 AimAt(const FVector& WorldLocation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = Shoot)
	float ShootRange;

	UPROPERTY(EditAnywhere, Category = Shoot)
	float ShootSpeed;

	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<AProjectile> BlueprintProjectile;

	UTankBarrel*			Barrel;
	UTankAimingComponent*	AimingComponent;
};
