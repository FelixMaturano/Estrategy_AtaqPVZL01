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
	UStaticMeshComponent* MeshPlanta;

	IEstrategiaAtaqueAZombies* EstrategiaAtaque;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// disparo  --------------


	

	//void NotifyActorBeginOverlap(AActor* OtherActor);



	void setEstrategiaAtaqueAZombies(AActor* _EstrategiaAtaqueAZombies);

	void disparar();

};
