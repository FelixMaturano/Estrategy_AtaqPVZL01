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


	bCanFire = true;
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.2f;

	//Energia = 200;
	TiempoTranscurrido = 0.0f;
	TiempoEntreDisparos = 1.0f;

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
	if (Health <= 0)
	{
		Destroy();
	}

	TiempoTranscurrido += DeltaTime;
	if (TiempoTranscurrido >= TiempoEntreDisparos) {

		atacarA(nullptr,FVector(0.0f, 1.0f, 0.0f));
		TiempoTranscurrido = 0.0f;
	}
}

void AEstrategiaAtaqueDisparo::atacarA(APlant* _plantaActual, FVector _ubicacionObjetivo)
{

//	// If it's ok to fire again
//// Si está bien disparar de nuevo
//	if (bCanFire == true)
//	{
//		// If we are pressing fire stick in a direction
//		// Si estamos presionando la palanca de disparo en una dirección
//		if (_ubicacionObjetivo.SizeSquared() > 0.0f)
//		{
//
//			const FRotator FireRotation = _ubicacionObjetivo.Rotation();
//
//			// Spawn projectile at an offset from this pawn
//			// Generar proyectil en un desplazamiento desde este peón
//			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);
//
//			UWorld* const World = GetWorld();
//			if (World != nullptr)
//			{
//				// spawn the projectile
//				// Generar el proyectil
//				World->SpawnActor<AProjectile>(SpawnLocation, FireRotation);
//			}
//
//			bCanFire = false;
//			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AEstrategiaAtaqueDisparo::ShotTimerExpired, FireRate);
//
//			// try and play the sound if specified
//			// Intentar reproducir el sonido si está especificado
//			//if (FireSound != nullptr)
//			//{
//				//UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
//			//}
//
//			//bCanFire = false;
//		}
//	}

		// Si está bien disparar de nuevo
	if (bCanFire)
	{
		if (_ubicacionObjetivo.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = _ubicacionObjetivo.Rotation();
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World)
			{
				// spawn the projectile
				AProjectile* Projectile = World->SpawnActor<AProjectile>(SpawnLocation, FireRotation);

				if (Projectile)
				{
					// Configura cualquier otra cosa necesaria para el proyectil
				}
			}

			// Configura el temporizador para que no pueda disparar de nuevo hasta que pase FireRate
			bCanFire = false;
			GetWorldTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AEstrategiaAtaqueDisparo::ShotTimerExpired, FireRate, false);
		}
	}
}
void AEstrategiaAtaqueDisparo::ShotTimerExpired()
{
	bCanFire = true;
}


void AEstrategiaAtaqueDisparo::ataquePlanta()
{

	atacarA(nullptr,FVector(0.0f, 1.0f, 0.0f));
}
float AEstrategiaAtaqueDisparo::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	// Aquí puedes manejar el daño como desees, por ejemplo, actualizando la salud del actor.
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Health Zombie: %f"), this->Health));

	Health -= Damage;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Health Zombie: %f"), this->Health));

	// Devuelve la cantidad de daño que se aplicó realmente.
	return Health;
}

