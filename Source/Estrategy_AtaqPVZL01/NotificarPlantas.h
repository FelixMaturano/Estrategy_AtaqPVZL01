// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Publicador.h"
#include "NotificarPlantas.generated.h"

/**
 * 
 */
class AZombie;
UCLASS()
class ESTRATEGY_ATAQPVZL01_API ANotificarPlantas : public APublicador
{
	GENERATED_BODY()
public:
	ANotificarPlantas();

//private:
	// La posicion actual del zombie
	//FVector pocisionZombie;
private:
	//The current time of this Clock Tower
	FString PosicionZombie;

public:

	void cambioPocisionZombie();

	void establecerPocisionZombie(FString _PocisionZombie);

	FORCEINLINE FString GetPosicionZombie() { return PosicionZombie; };
};
