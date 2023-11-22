// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"


class UProjectileMovementComponent;
class UStaticMeshComponent;
UCLASS()
class ESTRATEGY_ATAQPVZL01_API AProjectile : public AActor
{
	GENERATED_BODY()
	/** Sphere collision component */
//componente de colision de esfera
protected:

	/** Function to handle the projectile hitting something */
//funcion para manejar el proyectil golpeando algo
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ProjectileMesh;

	/** Projectile movement component */
	//componente de movimiento de proyectil
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

public:
	// Sets default values for this actor's properties
	AProjectile();


	/** Function to handle the projectile hitting something */
	//funcion para manejar el proyectil golpeando algo
	//UFUNCTION()
	//void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns ProjectileMesh subobject **/
	//retorna el subobjeto de malla de proyectil
	FORCEINLINE UStaticMeshComponent* GetProjectileMesh() const { return ProjectileMesh; }

	/** Returns ProjectileMovement subobject **/
	//retorna el subobjeto de movimiento de proyectil
	FORCEINLINE UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }

public:
	// Called every frame
	//llamado cada frame
	virtual void Tick(float DeltaTime) override;

	float DamageGenerates = 10.0f;
	float MaxDistance = 800.0f;

};
