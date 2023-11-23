// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaAplastamientoAZ.h"
#include "Plant.h"
#include "Zombie.h"
#include <Kismet/GameplayStatics.h>
#include "TimerManager.h"

// Sets default values
AEstrategiaAplastamientoAZ::AEstrategiaAplastamientoAZ()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstrategiaAplastamientoAZ::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategiaAplastamientoAZ::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstrategiaAplastamientoAZ::atacarA(APlant* _plantaActual, FVector _ubicacionObjetivo)
{
    APlant* plant;
    plant = _plantaActual;
    plant->MovementSpeed = 1000.0f;
    TArray<AActor*> Zombies;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlant::StaticClass(), Zombies);

    for (int32 i = 0; i < Zombies.Num(); i++)
    {
        // comparar la posicion x de la Planta con la del zombie
        if (FMath::IsNearlyEqual(Zombies[i]->GetActorLocation().X, plant->GetActorLocation().X, 0.1f))
        {
            // guardar la ubicacion inicial del zombie y la distancia inicial y no entrar más al if
            if (plant->DistanciaInicial == 0.0f)
            {
                plant->UbicacionInicial = plant->GetActorLocation();
                plant->DistanciaInicial = FVector::Dist(plant->UbicacionInicial, Zombies[i]->GetActorLocation());
            }

            // si la posicion x de la planta es igual a la del zombie, entonces la planta es el objetivo
            float AlturaSaltoInicial = plant->AlturaSalto; // Almacena la altura de salto inicial

            plant->LocalizacionObjetivo = Zombies[i]->GetActorLocation() + FVector(0.0f, 0.0f, plant->AlturaSalto);

            // Calcula la distancia recorrida en el salto
            float DistanciaRecorrida = FVector::Dist(plant->UbicacionInicial, plant->GetActorLocation());

            // Ajusta la altura del objetivo en función de la velocidad y la proporción recorrida

            plant->AlturaSalto = FMath::Max(AlturaSaltoInicial * (1.0f - DistanciaRecorrida / plant->DistanciaInicial) * plant->MovementSpeed / 200.0f, 0.0f);

            // calcula la direccion y distancia al objetivo
            plant->Direccion = (plant->LocalizacionObjetivo - plant->GetActorLocation()).GetSafeNormal();
            // calcula la distancia al objetivo
            plant->DistanciaAlObjetivo = FVector::Dist(plant->LocalizacionObjetivo, plant->GetActorLocation());

            float DeltaMove = _plantaActual->MovementSpeed * GetWorld()->DeltaTimeSeconds;

            if (DeltaMove > plant->DistanciaAlObjetivo)
            {
                // Si el desplazamiento excede la distancia al objetivo, mueve directamente al objetivo
                _plantaActual->SetActorLocation(_ubicacionObjetivo);

            }
            else
            {
                // Mueve el objeto en la direcci�n calculada
                _plantaActual->AddActorWorldOffset(plant->Direccion * DeltaMove);
            }

        }
    }
    Zombies.Empty();
    //GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Zombie estrategia saltar"));


}

