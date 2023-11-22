// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EstrategiaAtaqueAZombies.generated.h"

class APlant;
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEstrategiaAtaqueAZombies : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ESTRATEGY_ATAQPVZL01_API IEstrategiaAtaqueAZombies
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void atacarA(APlant* _plantaActual, FVector _ubicacionObjetivo) = 0;
};
