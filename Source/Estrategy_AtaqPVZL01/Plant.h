// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EstrategiaAtaqueAZombies.h"
#include "Plant.generated.h"


UCLASS()
class ESTRATEGY_ATAQPVZL01_API APlant : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlant();	// Sets default values for this actor's properties


	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshPlanta;

	IEstrategiaAtaqueAZombies* EstrategiaAtaque;

	float AlturaSalto = 0.0f;
	float DistanciaInicial;
	FVector UbicacionInicial;
	FVector LocalizacionObjetivo;
	FVector Direccion;
	float DistanciaAlObjetivo;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// disparo  --------------
	float DamageGenerates = 10.0f;
	float Health = 500.0f;
	float SpawnAfter = 0.0f;
	float MovementSpeed = 6.1f;
	bool bCanMove = false;

	float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser);
	void MoveToTarget(FVector TargetLocation);

	virtual void Attack() PURE_VIRTUAL(AZombie::Attack, );

	FORCEINLINE void SetSpawnAfter(float _SpawnAfter) { SpawnAfter = _SpawnAfter; }
	FORCEINLINE float GetSpawnAfter() { return SpawnAfter; }
	FORCEINLINE void SetCanMove(bool _bCanMove) { bCanMove = _bCanMove; }

	void setEstrategiaAtaqueAZombies(AActor* _estrategiaAtaqueAZombies);
	//void moverse();



	//void NotifyActorBeginOverlap(AActor* OtherActor);




	void disparar();
	//------------------------------------------------------
public:
	/** Offset from the ships location to spawn projectiles */
	// Desplazamiento desde la ubicación de la nave para generar proyectiles 
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	FVector GunOffset;
	FVector GetGunOffset() const { return GunOffset; }
	void SetGunOffset(FVector Value) { GunOffset = Value; }

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


	float TiempoTranscurrido;
	float TiempoEntreDisparos;

	

public:

	FString NombrePlantas;

	/* Flag to control firing  */
	// Bandera para controlar el disparo 
	uint32 bCanFire : 1;
	uint32 GetCanFire() const { return bCanFire; }
	void SetCanFire(uint32 Value) { bCanFire = Value; }

	/** Handle for efficient management of ShotTimerExpired timer */
	// Manejador para una gestión eficiente del temporizador ShotTimerExpired 
	FTimerHandle TimerHandle_ShotTimerExpired;

};