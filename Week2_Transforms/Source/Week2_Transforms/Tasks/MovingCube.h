// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingCube.generated.h"

UCLASS()
class WEEK2_TRANSFORMS_API AMovingCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingCube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere, Category="Components")
	UStaticMeshComponent* Mesh;

	// Speed to rotate the Actor. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variables", meta = (AllowPrivateAccess = "true")) // Private specifier added as we can't make something Blueprint Read/Writeable in the Private section by default. 
	float MovementRate = 2.0f; 

	// How many seconds between switching rotation direction. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variables", meta = (AllowPrivateAccess = "true"))
	float TimeBetweenSwitch = 5.0f; 

	// Variable to be tracked in the EventTick.
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category="Variables", meta = (AllowPrivateAccess = "true"))
	float CurrentTime = 0.0f; 
};
