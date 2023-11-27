// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EstrategiaAtaqueAZombies.h"
#include "EstrategiaAplastamientoAZ.h"
#include "Suscriptor.h"
#include "NotificarPlantas.h"
#include "Transformar.h"
#include "Plant.generated.h"


class AEstrategiaAplastamientoAZ;
class ANotificarPlantas;

UCLASS()
class ESTRATEGY_ATAQPVZL01_API APlant : public AActor, public ISuscriptor, public ITransformar
{
	GENERATED_BODY()

public:
	APlant();
public:
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshPlanta;

	IEstrategiaAtaqueAZombies* EstrategiaAtaque;

	float AlturaSalto = 8.0f;
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

	TArray<  APlant* > Plantas;


	UPROPERTY(EditAnywhere)
	APlant* PlantActorReference; // Referencia al actor que contiene el array Plantas

	class AZombie* Zombie;
	
private:
	//The Clock Tower of this Subscriber
	UPROPERTY()
	class ANotificarPlantas* Notificador;

	virtual void Destroyed() override;

public:
	//Called when the Plublisher changed its state, it will execute this Subscriber routine
	virtual void notificarPocisionZombie(class APublicador* Publicador) override;
	//Execute this Subscriber routine
	virtual void Cambios();
	//Set the Clock Tower of this Subscriber
	void DefinirNotificarPlantas(ANotificarPlantas* myNotificarPlantas);
	//----------------------------------------------------------------------------
	FString EstrategiaPlanta;
};