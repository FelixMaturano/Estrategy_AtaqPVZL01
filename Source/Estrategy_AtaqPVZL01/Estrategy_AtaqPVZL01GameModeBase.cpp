// Copyright Epic Games, Inc. All Rights Reserved.


#include "Estrategy_AtaqPVZL01GameModeBase.h"
#include "Plant.h"
#include "Zombie.h"

#include"EstrategiaAtaqueDisparo.h"
#include "EstrategiaAplastamientoAZ.h"


AEstrategy_AtaqPVZL01GameModeBase::AEstrategy_AtaqPVZL01GameModeBase()
{

	PrimaryActorTick.bCanEverTick = true;
}



void AEstrategy_AtaqPVZL01GameModeBase::BeginPlay()
{
	Super::BeginPlay();

	EstrategiaAplastamientoAZ = GetWorld()->SpawnActor<AEstrategiaAplastamientoAZ>(AEstrategiaAplastamientoAZ::StaticClass());


	//Definiendo la posición de los zombies
	FVector SpawnLocationZombie = FVector(-250.0f, 490.0f, 25.0f);

	//Genera 5 zombies
	for (int i = 0; i < 1; i++) {
		//	 Define una posición temporal para el zombie en X
		SpawnLocationZombie.X += 100;
		//Aparicion de los zombies


		NuevoZombie = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), SpawnLocationZombie, FRotator::ZeroRotator);

		NuevoZombie->Velocidad = 0.18;//FMath::FRandRange(0.01f, 0.3f);

		NuevoZombie->SetActorHiddenInGame(false);      // Haz que el actor sea visible
		NuevoZombie->SetActorEnableCollision(true);     // Habilita las colisiones si es necesario
		NuevoZombie->SetCanMove(true);     // Habilita las colisiones si es necesario
		//NumberZombiesSpawned += 1;


		Zombies.Add(NuevoZombie);

	}


	FVector SpawnLocationPlant = FVector(-250.0f, -440.0f, 25.0f);

	//Genera 5 zombies
	for (int i = 0; i < 1; i++) {
		//	 Define una posición temporal para el zombie en X
		SpawnLocationPlant.X += 100;
		//Aparicion de los zombies


		NuevaPlanta = GetWorld()->SpawnActor<APlant>(APlant::StaticClass(), SpawnLocationPlant, FRotator::ZeroRotator);
		NuevaPlanta->SetActorEnableCollision(true);

		Plantass.Add(NuevaPlanta);

	}

	
}


void AEstrategy_AtaqPVZL01GameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	////TiempoTranscurrido += DeltaTime;

	timerhandle += DeltaTime;
	APlant *plantas ;
	if (timerhandle >= 9.0f) {
		for (int32 i = 0; i < Plantass.Num(); i++) {
			plantas = Cast<APlant>(Plantass[i]);
			if (plantas) {
				plantas->setEstrategiaAtaqueAZombies(EstrategiaAplastamientoAZ);

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
APlant* AEstrategy_AtaqPVZL01GameModeBase::SpawnPlantas(FVector _spawnPosition)
{
	FTransform SpawnLocation;
	SpawnLocation.SetLocation(_spawnPosition);
	return GetWorld()->SpawnActor<APlant>(APlant::StaticClass(), SpawnLocation);

}

AZombie* AEstrategy_AtaqPVZL01GameModeBase::SpawnZombies(FVector _spawnPosition)
{
	FTransform SpawnLocation;
	SpawnLocation.SetLocation(_spawnPosition);
	return GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), SpawnLocation);

}
