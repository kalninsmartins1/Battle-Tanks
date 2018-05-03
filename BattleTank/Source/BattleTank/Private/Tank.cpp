// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"

// Sets default values
ATank::ATank()
	: ShootRange(1000000.0f)
	, ShootSpeed(100000.0f)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Tank aiming component"));
	if (AimingComponent == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Error something went siriously wrong and aiming component failed to create !"));
	}
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

float ATank::GetShootRange() const
{
	return ShootRange;
}

void ATank::SetBarrelComponent(UTankBarrel* BarrelComponent)
{	
	AimingComponent->SetBarrelComponent(BarrelComponent);
}

void ATank::SetTurretComponent(UTankTurret* TurretComponent)
{
	AimingComponent->SetTurretComponent(TurretComponent);
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(const FVector& WorldLocation)
{
	if (AimingComponent != nullptr)
	{
		AimingComponent->AimAt(WorldLocation, ShootSpeed);
	}
}

