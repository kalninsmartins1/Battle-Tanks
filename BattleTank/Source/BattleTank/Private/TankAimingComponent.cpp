// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"


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

void UTankAimingComponent::AimAt(const FVector& WorldLocation)
{
	AActor* Owner = GetOwner();
	if (Owner != nullptr && BarrelComponent != nullptr)
	{
		const FString& CurTankName = Owner->GetName();
		const FVector& BarrelLocation = BarrelComponent->GetComponentLocation();
		UE_LOG(LogTemp, Warning, TEXT("Tank %s aiming at %s from %s"), 
			*CurTankName, 
			*WorldLocation.ToString(), 
			*BarrelLocation.ToString());
	}
}

