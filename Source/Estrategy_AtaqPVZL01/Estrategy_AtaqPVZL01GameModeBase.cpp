// Copyright Epic Games, Inc. All Rights Reserved.


#include "Estrategy_AtaqPVZL01GameModeBase.h"
#include "Plant.h"
#include "Zombie.h"
#include"EstrategiaAtaqueDisparo.h"
#include "EstrategiaAplastamientoAZ.h"

#include "Kismet/GameplayStatics.h"


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
	for (int i = 0; i < 2; i++) {
		//	 Define una posición temporal para el zombie en X
		SpawnLocationZombie.X += 300;
		//Aparicion de los zombies
		NuevoZombie = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), SpawnLocationZombie, FRotator::ZeroRotator);

		NuevoZombie->Velocidad = FMath::FRandRange(0.053f, 0.06f);

		NuevoZombie->SetActorHiddenInGame(false);      // Haz que el actor sea visible
		NuevoZombie->SetActorEnableCollision(true);     // Habilita las colisiones si es necesario
		NuevoZombie->SetCanMove(true);     // Habilita las colisiones si es necesario
		//NumberZombiesSpawned += 1;

		Zombies.Add(NuevoZombie);

	}


	FVector SpawnLocationPlant = FVector(-250.0f, -440.0f, 25.0f);

	//Genera 5 zombies
	for (int i = 0; i < 2; i++) {
		//	 Define una posición temporal para el zombie en X
		SpawnLocationPlant.X += 300;
		//Aparicion de los zombies

		//APlant* plantatia;
		NuevaPlanta = GetWorld()->SpawnActor<APlant>(APlant::StaticClass(), SpawnLocationPlant, FRotator::ZeroRotator);
		NuevaPlanta->SetActorEnableCollision(true);

		PlantArray.Add(NuevaPlanta);

	}
}


void AEstrategy_AtaqPVZL01GameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//////timerhandle+=DeltaTime;
	PosicionActualZombie = NuevoZombie->GetActorLocation();
	if (PosicionActualZombie.Y < 0.0f) {
		for (int32 i = 0; i < PlantArray.Num(); i++)
		{
			
			//	APlant* planta = Cast<APlant>(PlantArray[i]);
				//if (planta)
			//{
		//	NuevoZombie->notificarPocisionZombie(PlantArray);
					//planta->setEstrategiaAtaqueAZombies(EstrategiaAplastamientoAZ);
					//// Crear una nueva instancia de AEstrategiaAplastamientoAZ
///////////////AEstrategiaAplastamientoAZ* NuevaEstrategia = GetWorld()->SpawnActor<AEstrategiaAplastamientoAZ>(AEstrategiaAplastamientoAZ::StaticClass());
			//planta->setEstrategiaAtaqueAZombies(NuevaEstrategia);
		//}
			PlantArray[i]->_HsidoNotificado = true;

		}

	}

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