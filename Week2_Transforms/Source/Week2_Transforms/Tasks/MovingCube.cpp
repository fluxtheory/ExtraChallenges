// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingCube.h"

// Sets default values
AMovingCube::AMovingCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingCube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (CurrentTime < TimeBetweenSwitch) {
		//UE_LOG(LogTemp, Warning, TEXT("Time Elapsed:%f"), CurrentTime);
		CurrentTime += DeltaTime;
		const FVector XDelta = FVector(MovementRate, 0.f, 0.f);
		AddActorLocalOffset(XDelta);
	}
	else {
		// flip direction once currentTime reaches timebetweenswitch
		CurrentTime = 0.f;
		MovementRate *= -1;
	}
}

