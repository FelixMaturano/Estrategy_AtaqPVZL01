// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Suscriptor.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USuscriptor : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ESTRATEGY_ATAQPVZL01_API ISuscriptor
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void notificarPocision(class AZombie* _Publicador) = 0;
};
