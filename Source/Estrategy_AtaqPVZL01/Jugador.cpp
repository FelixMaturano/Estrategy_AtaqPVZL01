// Fill out your copyright notice in the Description page of Project Settings.


#include "Jugador.h"
#include "Plant.h"
#include "Zombie.h"

#include "Kismet/GameplayStatics.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"

// Sets default values
AJugador::AJugador()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm


	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	CameraComponent->SetupAttachment(RootComponent);
	contador = 0;
	Localizacion = FVector(400.0, 400.0, 100.0);

}

// Called when the game starts or when spawned
void AJugador::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJugador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Obtén el jugador que controla la cámara
	//PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0); // 0 para el primer jugador



	//if (APlayerController* PC = Cast<APlayerController>(GetController()))
	//{
	//	if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
	//	{
	//		if (UCameraComponent* OurCamera = PC->GetViewTarget()->FindComponentByClass<UCameraComponent>())
	//		{

	//			FVector Start = OurCamera->GetComponentLocation();
	//			FVector End = Start + (OurCamera->GetComponentRotation().Vector() * 8000.0f);

	//			SeguimientoGrilla(Start, End, true);
	//			SeguimientoSol(Start, End, true);

	//		}
	//	}
	//	else
	//	{
	//		FVector Start, Dir, End;
	//		PC->DeprojectMousePositionToWorld(Start, Dir);

	//		End = Start + (Dir * 8000.0f);

	//		SeguimientoGrilla(Start, End, false);
	//		SeguimientoSol(Start, End, false);

	//	}

	//}
}

// Called to bind functionality to input
void AJugador::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AJugador::TriggerClick()
{
}

void AJugador::SeguimientoGrilla(const FVector& Start, const FVector& End, bool bDrawDebugHelpers)
{


}

void AJugador::SeguimientoSol(const FVector& Start, const FVector& End, bool bDrawDebugHelpers)
{



}

