// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EstrategiaAtaqueAZombies.h"
#include "EstrategiaAtaqueDisparo.generated.h"

class APlant;
class AZombie;
class AProjectile;
UCLASS()
class ESTRATEGY_ATAQPVZL01_API AEstrategiaAtaqueDisparo : public AActor, public IEstrategiaAtaqueAZombies
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEstrategiaAtaqueDisparo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame-------------------------------------------------------------------
	virtual void Tick(float DeltaTime) override;
	virtual void atacarA(APlant* _plantaActual, FVector _ubicacionObjetivo)override;

public:
	/** Offset from the ships location to spawn projectiles */
	// Desplazamiento desde la ubicación de la nave para generar proyectiles 
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	FVector GunOffset;

	/* How fast the weapon will fire */
	// La velocidad a la que el arma disparará 
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float FireRate;

	/* Fire a shot in the specified direction */
	// Disparar un proyectil en la dirección especificada 
	///////void FireShot(FVector FireDirection);

	/* Handler for the fire timer expiry */
	// Manejador para la expiración del temporizador de disparo 
	void ShotTimerExpired();

	void ataquePlanta();

	float TiempoTranscurrido;
	float TiempoEntreDisparos;

	float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser);
	float Health = 20.0f;

protected:

	FString NombrePlantas;

	/* Flag to control firing  */
	// Bandera para controlar el disparo 
	uint32 bCanFire : 1;

	/** Handle for efficient management of ShotTimerExpired timer */
	// Manejador para una gestión eficiente del temporizador ShotTimerExpired 
	FTimerHandle TimerHandle_ShotTimerExpired;
};
