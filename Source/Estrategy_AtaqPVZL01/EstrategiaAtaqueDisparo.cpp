// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaAtaqueDisparo.h"
#include "Plant.h"
#include "Projectile.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
AEstrategiaAtaqueDisparo::AEstrategiaAtaqueDisparo()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstrategiaAtaqueDisparo::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AEstrategiaAtaqueDisparo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstrategiaAtaqueDisparo::atacarA(APlant* _plantaActual, FVector _ubicacionObjetivo)
{

    UE_LOG(LogTemp, Warning, TEXT("Dispirando al Zombies"));
    GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, TEXT("Disparando al zombie"));

    APlant* planta;
    planta = _plantaActual;

    FVector NewOffset = FVector(90.f, 0.f, 0.f);
    planta->SetGunOffset(NewOffset);

    if (planta->bCanFire) // Corrección en la condición
    {
        if (_ubicacionObjetivo.SizeSquared() > 0.0f)
        {
            const FRotator FireRotation = _ubicacionObjetivo.Rotation();
            const FVector SpawnLocation = planta->GetActorLocation() + FireRotation.RotateVector(NewOffset);

            UWorld* const World = planta->GetWorld();
            if (World != nullptr)
            {
                // spawn the projectile
                World->SpawnActor<AProjectile>(SpawnLocation, FireRotation);
            }

            planta->bCanFire = false;

            // Corrección en la configuración del temporizador
            World->GetTimerManager().SetTimer(planta->TimerHandle_ShotTimerExpired, planta, &APlant::ShotTimerExpired, planta->FireRate);
        }
    }

}



