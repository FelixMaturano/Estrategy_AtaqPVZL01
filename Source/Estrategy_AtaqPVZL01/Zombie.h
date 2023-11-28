// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Suscriptor.h"
#include"Plant.h"
#include "Publicador.h"
#include "Components/BoxComponent.h"
#include "Zombie.generated.h"

class UStaticMeshComponent;
class APlant;
class AEstrategiaAplastamientoAZ;
class APublicador;
UCLASS()
class ESTRATEGY_ATAQPVZL01_API AZombie : public AActor
{
	GENERATED_BODY()
	
public:	
	AZombie();

private:
    UPROPERTY(EditAnywhere)
	TArray<APlant*> plantasSuscriptores;
	
public:
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* ZombieMeshComponent;

	AEstrategiaAplastamientoAZ* EstrategiaAplastamientoAZ;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float Velocidad;

	UPROPERTY(EditAnywhere)
	float Energia;

	FTimerHandle Temporizador;

	void morir();

	FString TagString;

	


	float DamageGenerates = 10.f;
	float Health = 10.0f;

	float SpawnAfter = 0.0f;
	float MovementSpeed = 6.1f;
	bool bCanMove = false;

	float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser);
	void MoveToTarget(FVector TargetLocation);


	FORCEINLINE void SetSpawnAfter(float _SpawnAfter) { SpawnAfter = _SpawnAfter; }
	FORCEINLINE float GetSpawnAfter() { return SpawnAfter; }
	FORCEINLINE void SetCanMove(bool _bCanMove) { bCanMove = _bCanMove; }

private:
	virtual void Destroyed() override;

	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal,
	FVector NormalImpulse, const FHitResult& Hit)override;//esta funcion nos notifica cada golpe que de la clase.

	UFUNCTION(BlueprintCallable, Category = "Custom")
	bool IsActorDestroyed() const;
public:
	// Implementación de la función notificarPocisionZombie de ISuscriptor
	virtual void notifPocisionASuscriptores();

	APlant* Suscriptores;

	FVector PosicionActualZombie;


};
