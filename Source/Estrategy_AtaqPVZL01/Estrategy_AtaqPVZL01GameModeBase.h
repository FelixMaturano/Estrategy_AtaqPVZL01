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
class AEstrategiaAtaqueDisparo;
UCLASS()
class ESTRATEGY_ATAQPVZL01_API AEstrategy_AtaqPVZL01GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AEstrategy_AtaqPVZL01GameModeBase();

	float timerhandle;
	AEstrategiaAtaqueDisparo* EstrategiaAtaqueDisparo;

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
	
};
