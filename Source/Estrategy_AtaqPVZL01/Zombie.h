// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Suscriptor.h"
#include "Components/BoxComponent.h"
#include "Zombie.generated.h"

class UStaticMeshComponent;
class APlant;
UCLASS()
class ESTRATEGY_ATAQPVZL01_API AZombie : public AActor, public ISuscriptor
{
	GENERATED_BODY()
	
public:	
	AZombie();
	//-----------------------------------------------observer=======================================

private:

	//Los suscrioptores y lo inicializamos
	UPROPERTY()
	TArray<AActor*> Subscribers = TArray<AActor*>();
	//-----------------------------------------------observer=======================================
public:
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* ZombieMeshComponent;



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

	float MovingX = 300.0f;

	FVector StartLocation;
	FVector EndLocation;
private:
	FVector CurrentLocation;
// ======observer===============================

private:
	APlant* planta;


	virtual void Destroyed() override;


	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal,
		FVector NormalImpulse, const FHitResult& Hit)override;//esta funcion nos notifica cada golpe que de la clase.


	UFUNCTION(BlueprintCallable, Category = "Custom")
	bool IsActorDestroyed() const;
public:
	// Implementación de la función notificarPocisionZombie de ISuscriptor
	virtual void notificarPocisionZombie(class APublicador* Publicador) override;
};
