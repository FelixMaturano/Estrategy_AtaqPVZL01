// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Components/BoxComponent.h"
#include "PlantaObservador.generated.h"

class APlant;
class AZombie;
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPlantaObservador : public UInterface
{
	GENERATED_BODY()
};
/**
 * 
 */
class ESTRATEGY_ATAQPVZL01_API IPlantaObservador
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void NotificadoPorZombie(const FVector& PosicionZombie) = 0;

};
