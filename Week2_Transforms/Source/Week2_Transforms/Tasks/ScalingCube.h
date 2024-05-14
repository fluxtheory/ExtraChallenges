// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScalingCube.generated.h"

UCLASS()
class WEEK2_TRANSFORMS_API AScalingCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScalingCube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variables", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh;

	// Rate of Scaling the Actor. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables", meta = (AllowPrivateAccess = "true")) // Private specifier added as we can't make something Blueprint Read/Writeable in the Private section by default. 
	float ScaleFactor = 0.002f;

	// How many seconds between switching scaling direction. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables", meta = (AllowPrivateAccess = "true"))
	float TimeBetweenSwitch = 3.0f;

	// Variable to be tracked in the EventTick.
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Variables", meta = (AllowPrivateAccess = "true"))
	float CurrentTime = 0.0f;

};
