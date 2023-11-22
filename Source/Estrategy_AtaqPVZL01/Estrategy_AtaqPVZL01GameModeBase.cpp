// Copyright Epic Games, Inc. All Rights Reserved.


#include "Estrategy_AtaqPVZL01GameModeBase.h"
#include "Plant.h"
#include "Zombie.h"

#include"EstrategiaAtaqueDisparo.h"

AEstrategy_AtaqPVZL01GameModeBase::AEstrategy_AtaqPVZL01GameModeBase()
{

	PrimaryActorTick.bCanEverTick = true;
}

void AEstrategy_AtaqPVZL01GameModeBase::BeginPlay()
{
	Super::BeginPlay();

	EstrategiaAtaqueDisparo = GetWorld()->SpawnActor<AEstrategiaAtaqueDisparo>(AEstrategiaAtaqueDisparo::StaticClass());


	//Definiendo la posición de los zombies
	FVector SpawnLocationZombie = FVector(-250.0f, 490.0f, 25.0f);

	//Genera 5 zombies
	for (int i = 0; i < 7; i++) {
		//	 Define una posición temporal para el zombie en X
		SpawnLocationZombie.X += 100;
		//Aparicion de los zombies


		NuevoZombie = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), SpawnLocationZombie, FRotator::ZeroRotator);

		NuevoZombie->Velocidad = FMath::FRandRange(0.01f, 0.05f);

		NuevoZombie->SetActorHiddenInGame(false);      // Haz que el actor sea visible
		NuevoZombie->SetActorEnableCollision(true);     // Habilita las colisiones si es necesario
		NuevoZombie->SetCanMove(true);     // Habilita las colisiones si es necesario
		//NumberZombiesSpawned += 1;


		Zombies.Add(NuevoZombie);

	}


	FVector SpawnLocationPlant = FVector(-250.0f, -440.0f, 25.0f);

	//Genera 5 zombies
	for (int i = 0; i < 7; i++) {
		//	 Define una posición temporal para el zombie en X
		SpawnLocationPlant.X += 100;
		//Aparicion de los zombies


		NuevaPlanta = GetWorld()->SpawnActor<APlant>(APlant::StaticClass(), SpawnLocationPlant, FRotator::ZeroRotator);
		NuevaPlanta->SetActorEnableCollision(true);

		Plantas.Add(NuevaPlanta);

	}

	
}

void AEstrategy_AtaqPVZL01GameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	////TiempoTranscurrido += DeltaTime;

	timerhandle += DeltaTime;

	if (timerhandle >= 2.0f) {
		for (int32 i = 0; i < Plantas.Num(); i++) {
			APlant* platas = Cast<APlant>(Plantas[i]);
			if (platas) {
				platas->setEstrategiaAtaqueAZombies(EstrategiaAtaqueDisparo);
			}
		}
	}

	//TiempoTranscurrido += DeltaTime;

	//if (TiempoTranscurrido >= 2.0f)
	//{
	//	for (APlant* Planta : Plantas)
	//	{
	//		if (Planta)
	//		{
	//			Planta->setEstrategiaAtaqueAZombies()->atacarA(Planta, FVector(0.0f, 1.0f, 0.0f));
	//		}
	//	}

	//	TiempoTranscurrido = 0.0f;
	//}
}
