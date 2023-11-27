// Fill out your copyright notice in the Description page of Project Settings.


#include "NotificarPlantas.h"
#include "Plant.h"


ANotificarPlantas::ANotificarPlantas()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ANotificarPlantas::cambioPocisionZombie()
{

	//When the time has changed, this Clock Tower (that is a Publisher) notifies to all the subscribers that the time has changed
	NotificarSuscriptores();
}

void ANotificarPlantas::establecerPocisionZombie(FString _PocisionZombie)
{

	//Set the time using the passed parameter and warn that it's changed
	PosicionZombie = _PocisionZombie;
	cambioPocisionZombie();
}


