// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Zombie.generated.h"

class UStaticMeshComponent;
UCLASS()
class ESTRATEGY_ATAQPVZL01_API AZombie : public AActor
{
	GENERATED_BODY()
	
public:	
	AZombie();

public:
	// metodo de notificacion******************************************************
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void MoverZombie();

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void SuscribirPlanta(TScriptInterface<IPlantaObservador> Observador);

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void DesuscribirPlanta(TScriptInterface<IPlantaObservador> Observador);
private:
	UPROPERTY()
	TArray<TScriptInterface<IPlantaObservador>> Observadores;

	UPROPERTY(EditAnywhere, Category = "Gameplay")
	float CoordenadaCruceZombie;
	//--------------------------------------------------------------------------
public:
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* ZombieMeshComponent;

	UFUNCTION()
	void OnOverlapBeginFunction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);


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

	void iniciarMovimiento();


	bool bHaNotificado=false;
private:
	FVector CurrentLocation;
};
