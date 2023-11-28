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
    UE_LOG(LogTemp, Warning, TEXT("LA SEGUNDA ESTRATEGIA:  Salto para aplastar "));
    GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("Aplastando al Zombie"));

    APlant* Plant = _plantaActual;
    Plant->MovementSpeed = 400.0f;

    // Obtener todos los zombies en el mundo
    TArray<AActor*> Zombies;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AZombie::StaticClass(), Zombies);

    // Encontrar el zombie más cercano
    AActor* ClosestZombie = nullptr;
    float ClosestDistance = TNumericLimits<float>::Max();

    for (AActor* Zombie : Zombies)
    {
        float Distance = FVector::Dist(Plant->GetActorLocation(), Zombie->GetActorLocation());
        if (Distance < ClosestDistance)
        {
            ClosestDistance = Distance;
            ClosestZombie = Zombie;
        }
    }

    if (ClosestZombie)
    {
        // Salta hacia el zombie más cercano
        Plant->LocalizacionObjetivo = ClosestZombie->GetActorLocation() + FVector(0.0f, 0.0f, Plant->AlturaSalto);

        // Calcula la distancia al objetivo
        Plant->DistanciaAlObjetivo = FVector::Dist(Plant->LocalizacionObjetivo, Plant->GetActorLocation());

        // Salta hacia el objetivo
        Plant->AlturaSalto = FMath::Max(Plant->AlturaSalto, Plant->AlturaSalto + 2.0f);

        float DeltaMove = Plant->MovementSpeed * GetWorld()->DeltaTimeSeconds;

        if (DeltaMove > Plant->DistanciaAlObjetivo)
        {
            // Si el desplazamiento excede la distancia al objetivo, mueve directamente al objetivo
            Plant->SetActorLocation(Plant->LocalizacionObjetivo);

            // Verifica si la planta ha aterrizado en el objetivo (zombie)
            if (FMath::IsNearlyEqual(Plant->GetActorLocation().Z, Plant->LocalizacionObjetivo.Z, 5.0f))
            {
                // La planta ha aterrizado, destruye al zombie
                ClosestZombie->Destroy();

                // Ajusta la posición Z para que la planta permanezca en el lugar exacto del zombie
                FVector NewLocation = ClosestZombie->GetActorLocation();
                NewLocation.Z = 25.0f; // Establece la posición Z deseada
                Plant->SetActorLocation(NewLocation);
            }

            // Restablece la altura del salto
            Plant->AlturaSalto = 0.0f;
        }
        else
        {
            // Mueve el objeto en la dirección calculada
            Plant->AddActorWorldOffset((Plant->LocalizacionObjetivo - Plant->GetActorLocation()).GetSafeNormal() * DeltaMove);
        }
    }
}