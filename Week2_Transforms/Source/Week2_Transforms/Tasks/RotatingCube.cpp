// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingCube.h"

// Sets default values
ARotatingCube::ARotatingCube()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create Mesh, ensure the component declared in the header is added to the class. 
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	// Make the mesh the RootComponent. Other components you add will be placed on this by default. 
	RootComponent = Mesh; 
}

// Called when the game starts or when spawned
void ARotatingCube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotatingCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// spin in one direction at rotationRate for timebetsweenswitch seconds
	if (CurrentTime < TimeBetweenSwitch) {
		//rotationRate is SPEED
		//UE_LOG(LogTemp, Warning, TEXT("Time Elapsed:%f"), CurrentTime);
		CurrentTime += DeltaTime;
		const FRotator CurrentRotation = FRotator(0.f,RotationRate * CurrentTime,0.f);
		SetActorRotation(CurrentRotation);
		//AddActorLocalRotation(CurrentRotation);
	}
	else {
		// flip direction once currentTime reaches timebetweenswitch
		CurrentTime = 0.f;
		RotationRate *= -1;
	}
	
}



