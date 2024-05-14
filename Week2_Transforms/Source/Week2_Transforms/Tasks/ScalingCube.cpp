// Fill out your copyright notice in the Description page of Project Settings.


#include "ScalingCube.h"

// Sets default values
AScalingCube::AScalingCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AScalingCube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AScalingCube::Tick(float DeltaTime)
{
	// KEEP calculations and math heavy stuff in c++, everything do it in BP.
	Super::Tick(DeltaTime);
	if (CurrentTime < TimeBetweenSwitch) {
		UE_LOG(LogTemp, Warning, TEXT("Time Elapsed:%f"), CurrentTime);
		CurrentTime += DeltaTime;
		const FVector CurrentScale = GetActorScale3D();
		const FVector NewScale = FVector(CurrentScale.X + ScaleFactor, CurrentScale.Y + ScaleFactor, CurrentScale.Z + ScaleFactor);
		SetActorScale3D(NewScale);
	}
	else {
		// flip direction once currentTime reaches timebetweenswitch
		CurrentTime = 0.0f;
		ScaleFactor *= -1;
	}
}

