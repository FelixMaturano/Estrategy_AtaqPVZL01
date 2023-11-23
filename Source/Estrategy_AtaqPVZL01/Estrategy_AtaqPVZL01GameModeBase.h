// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Estrategy_AtaqPVZL01GameModeBase.generated.h"

/**
 * 
 */

class APlant;
class AZombie;
//class AEstrategiaAtaqueDisparo;
class AEstrategiaAplastamientoAZ;
UCLASS(MinimalAPI)
class ESTRATEGY_ATAQPVZL01_API AEstrategy_AtaqPVZL01GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AEstrategy_AtaqPVZL01GameModeBase();

	float timerhandle;
	
	AEstrategiaAplastamientoAZ* EstrategiaAplastamientoAZ;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;

public:
	TArray< APlant* > Plantas;
	APlant* NuevaPlanta;

	float TiempoTranscurrido;
	TArray<AZombie*> Zombies;
	AZombie* NuevoZombie;
	

	class APlant* SpawnPlantas(FVector _spawnPosition);
	class AZombie* SpawnZombies(FVector _spawnPosition);
};
