// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EstrategiaAtaqueAZombies.h"
#include "EstrategiaAtaqueDisparo.generated.h"

class APlant;
class AZombie;
class AProjectile;
UCLASS()
class ESTRATEGY_ATAQPVZL01_API AEstrategiaAtaqueDisparo : public AActor, public IEstrategiaAtaqueAZombies
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEstrategiaAtaqueDisparo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame-------------------------------------------------------------------
	virtual void Tick(float DeltaTime) override;
	virtual void atacarA(APlant* _plantaActual, FVector _ubicacionObjetivo)override;


};