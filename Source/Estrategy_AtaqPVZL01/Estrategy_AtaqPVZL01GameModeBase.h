// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlantaObservador.h"
#include "Estrategy_AtaqPVZL01GameModeBase.generated.h"

/**
 * 
 */
class IPlantaObservador;
class AEstrategiaAplastamientoAZ;
class APlant;
UCLASS()
class ESTRATEGY_ATAQPVZL01_API AEstrategy_AtaqPVZL01GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AEstrategy_AtaqPVZL01GameModeBase();

	float timerhandle;


	AEstrategiaAplastamientoAZ* EstrategiaAplastamientoAZe;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;

public:
	TArray< class APlant* > Plantas;
	APlant* NuevaPlanta;

	float TiempoTranscurrido;
	TArray<class AZombie*> Zombies;
	AZombie* NuevoZombie;
	

	class APlant* SpawnPlantas(FVector _spawnPosition);
	class AZombie* SpawnZombies(FVector _spawnPosition);

	float ElapsedTime;

	// Funci�n para notificar a todas las plantas como observadoras
	void NotifyPlants();

	// Declaraci�n de observadores
	TArray<IPlantaObservador*> PlantObservers;

	// Funci�n para suscribir observadores
	void SubscribeToPlantEvents(IPlantaObservador* Observer)
	{
		if (Observer)
		{
			PlantObservers.AddUnique(Observer);
		}
	}
	// Funci�n para cambiar la estrategia cuando se recibe una notificaci�n
	void ChangeStrategyOnNotification();
};
