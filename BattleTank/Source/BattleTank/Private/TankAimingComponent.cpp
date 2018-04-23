// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine//Classes/Components/StaticMeshComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}

void UTankAimingComponent::SetBarrelComponent(UStaticMeshComponent* BarrelComponent)
{
	this->BarrelComponent = BarrelComponent;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(const FVector& WorldLocation, float ShootSpeed)
{	
	if (BarrelComponent != nullptr)
	{
		const FVector StartLocation = BarrelComponent->GetSocketLocation(FName("Projectile"));
		
		FVector OutShootDirection;
		if (UGameplayStatics::SuggestProjectileVelocity(this, OutShootDirection, StartLocation, WorldLocation, ShootSpeed, false))
		{
			OutShootDirection.Normalize();
			UE_LOG(LogTemp, Warning, TEXT("Shoot direction %s"), *OutShootDirection.ToString());
		}
		else
		{
			// Do nothing, no solution found
		}
	}
}

