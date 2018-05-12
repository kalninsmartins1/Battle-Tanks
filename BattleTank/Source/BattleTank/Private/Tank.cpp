// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
	: ShootRange(1000000.0f)
	, ShootSpeed(4000.0f)
	, ReloadTimeInSeconds(3.0f)
	, LastFireTime(0)
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
	Barrel = BarrelComponent;
	AimingComponent->SetBarrelComponent(BarrelComponent);
}

void ATank::SetTurretComponent(UTankTurret* TurretComponent)
{
	AimingComponent->SetTurretComponent(TurretComponent);
}

void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (Barrel != nullptr && isReloaded)
	{
		FVector StartLocation;
		AimingComponent->GetShootingStartLocation(StartLocation);

		FRotator StartRotation;
		AimingComponent->GetShootingStartRotation(StartRotation);
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(BlueprintProjectile, StartLocation, StartRotation);
		Projectile->LaunchProjectile(ShootSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
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

