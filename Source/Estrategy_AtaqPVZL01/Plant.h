// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EstrategiaAtaqueAZombies.h"
#include "PlantaObservador.h"
#include"EstrategiaAplastamientoAZ.h"
#include "Components/BoxComponent.h"
#include "Plant.generated.h"


UCLASS()
class ESTRATEGY_ATAQPVZL01_API APlant : public AActor, public IPlantaObservador
{
	GENERATED_BODY()

public:
	
	APlant();	

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshPlanta;

	IEstrategiaAtaqueAZombies* EstrategiaAtaque;
	//IEstrategiaAtaqueDisparo* EstrategiaAtaqueDisparo;
	//IEstrategiaAtaqueAplastamiento* EstrategiaAtaqueAplastamiento;

	float AlturaSalto = 8.0f;
	float DistanciaInicial;
	FVector UbicacionInicial;
	FVector LocalizacionObjetivo;
	FVector Direccion;
	float DistanciaAlObjetivo;

	// nuesta funcion de notificacion******************************************************
	IPlantaObservador* notificador;
	virtual void NotificadoPorZombie(const FVector& PosicionZombie) override;
	void notificarOtrasPlantas();
	void setNotificarOtrasPlantas(AActor* _notificarOtrasPlantas);
	

	void CambiarEstrategia();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// disparo  --------------
	float DamageGenerates = 10.0f;
	float Health = 50.0f;
	float SpawnAfter = 0.0f;
	float MovementSpeed ;
	bool bCanMove = false;

	float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser);
	void MoveToTarget(FVector TargetLocation);

	virtual void Attack() PURE_VIRTUAL(AZombie::Attack, );

	FORCEINLINE void SetSpawnAfter(float _SpawnAfter) { SpawnAfter = _SpawnAfter; }
	FORCEINLINE float GetSpawnAfter() { return SpawnAfter; }
	FORCEINLINE void SetCanMove(bool _bCanMove) { bCanMove = _bCanMove; }

	void setEstrategiaAtaqueAZombies(IEstrategiaAtaqueAZombies* _estrategiaAtaqueAZombies);
	float timerhandle;

	void atacar(const FVector& TargetLocation);
	
public:
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	FVector GunOffset;
	
	FVector GetGunOffset() const { return GunOffset; }
	void SetGunOffset(FVector Value) { GunOffset = Value; }

	// La velocidad a la que el arma disparará 
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float FireRate;
	
	void ShotTimerExpired();

	float TiempoTranscurrido;
	float TiempoEntreDisparos;

	

public:

	
	// Bandera para controlar el disparo 
	uint32 bCanFire : 1;
	uint32 GetCanFire() const { return bCanFire; }
	void SetCanFire(uint32 Value) { bCanFire = Value; }

	// Manejador para una gestión eficiente del temporizador ShotTimerExpired 
	FTimerHandle TimerHandle_ShotTimerExpired;

	bool bHaSidoNotificada = false;
	APlant* esto;

};