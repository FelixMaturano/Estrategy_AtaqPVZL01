// Fill out your copyright notice in the Description page of Project Settings.


#include "Plant.h"
#include "Projectile.h"
#include "Zombie.h"
#include "EstrategiaAtaqueDisparo.h"
#include "EstrategiaAtaqueAZombies.h"
#include "EstrategiaAplastamientoAZ.h"

#include "PlantaObservador.h"

#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
APlant::APlant()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlantaMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	MeshPlanta = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlantMesh"));
	MeshPlanta->SetStaticMesh(PlantaMesh.Object);
	MeshPlanta->SetRelativeScale3D(FVector(0.25f, 0.29f, 0.35f));

	RootComponent = MeshPlanta;

	MeshPlanta->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	MeshPlanta->SetSimulatePhysics(false);
	MeshPlanta->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	bCanFire = true;
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.2f;
	//Energia = 200;
	TiempoTranscurrido = 0.0f;
	TiempoEntreDisparos = 1.0f;

	DamageGenerates = 10.0f;
	Health = 50.0f;
	MovementSpeed = 0.0001f;
	bCanMove = false;
}


void APlant::NotificadoPorZombie(const FVector& PosicionZombie)
{
	// Lógica para cambiar la estrategia inmediatamente
	CambiarEstrategia();

	// Otras acciones que puedas necesitar realizar al ser notificado
	auto Message = FString::Printf(TEXT("Zombie cerca en la posición: %s. Cambiando estrategia."), *PosicionZombie.ToString());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, Message);
	bool cambiado = true;
}

void APlant::notificarOtrasPlantas()
{
	UWorld* World = GetWorld();
	if (!World)
	{
		UE_LOG(LogTemp, Error, TEXT("No se puede obtener el mundo"));
		return;
	}

	TArray<AActor*> OtrasPlants;
	UGameplayStatics::GetAllActorsOfClass(World, APlant::StaticClass(), OtrasPlants);

	for (AActor* OtrasPlant : OtrasPlants)
	{
		APlant* Plant = Cast<APlant>(OtrasPlant);
		if (Plant && Plant != this)
		{
			Plant->NotificadoPorZombie(LocalizacionObjetivo);
		}
	}
}

void APlant::setNotificarOtrasPlantas(AActor* _notificarOtrasPlantas)
{
	notificador = Cast<IPlantaObservador>(_notificarOtrasPlantas);
}

void APlant::CambiarEstrategia()
{
	if (EstrategiaAtaque)
	{
		// Si ya tenemos una estrategia, cambiamos a estrategia de aplastamiento
		AEstrategiaAplastamientoAZ* NuevaEstrategia = GetWorld()->SpawnActor<AEstrategiaAplastamientoAZ>(AEstrategiaAplastamientoAZ::StaticClass());
		setEstrategiaAtaqueAZombies(NuevaEstrategia);

		// Puedes agregar más lógica aquí según tus necesidades
		// Por ejemplo, ajustar parámetros de la planta, cambiar animaciones, etc.
	}
	else
	{
		// Si no tenemos una estrategia, cambiamos a una estrategia de disparo
		AEstrategiaAtaqueDisparo* NuevaEstrategia = GetWorld()->SpawnActor<AEstrategiaAtaqueDisparo>(AEstrategiaAtaqueDisparo::StaticClass());
		setEstrategiaAtaqueAZombies(NuevaEstrategia);

		// Puedes agregar más lógica aquí según tus necesidades
		// Por ejemplo, ajustar parámetros de la planta, cambiar animaciones, etc.
	}
}

// Called when the game starts or when spawned
void APlant::BeginPlay()
{
	Super::BeginPlay();

	AEstrategiaAtaqueDisparo* estrategiaAtaqueDisparo = GetWorld()->SpawnActor<AEstrategiaAtaqueDisparo>(AEstrategiaAtaqueDisparo::StaticClass());
	setEstrategiaAtaqueAZombies(estrategiaAtaqueDisparo);
}

// Called every frame
void APlant::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	//timerhandle += DeltaTime;

	atacar(LocalizacionObjetivo);

}

float APlant::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	// Aqu? puedes manejar el da?o como desees, por ejemplo, actualizando la salud del actor.
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Health Zombie: %f"), this->Health));

	Health -= Damage;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Health Zombie: %f"), this->Health));

	// Devuelve la cantidad de da?o que se aplic? realmente.
	return Health;
}

void APlant::MoveToTarget(FVector TargetLocation)
{
	FVector Direction = TargetLocation - FVector(-250.0f, 490.0f, 25.0f);
	float DistanceToTarget = FVector::Dist(TargetLocation, FVector(-250.0f, 490.0f, 25.0f));

	// Calcula el desplazamiento en este frame
	float DeltaMove = MovementSpeed * GetWorld()->DeltaTimeSeconds;

	if (DeltaMove > DistanceToTarget)
	{
		// Si el desplazamiento excede la distancia al objetivo, mueve directamente al objetivo
		this->SetActorLocation(TargetLocation);

	}
	else
	{
		// Mueve el objeto en la direcci?n calculada
		this->AddActorWorldOffset(Direction * DeltaMove);

	}
}

//void APlant::setEstrategiaAtaqueAZombies(AActor* _estrategiaAtaqueAZombies)
//{
//
//	EstrategiaAtaque = Cast<IEstrategiaAtaqueAZombies>(_estrategiaAtaqueAZombies);
//
//	//Log Error if the cast failed
//	if (!EstrategiaAtaque)
//	{
//		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("Invalid Cast! See Output log for more details"));
//		UE_LOG(LogTemp, Error, TEXT("Moverse(): The Actor is not a estrategia de movimiento!Are you sure that the Actor implements that interface ? "));
//	}
//
//
//}


void APlant::ShotTimerExpired()
{
	bCanFire = true;
}

void APlant::setEstrategiaAtaqueAZombies(IEstrategiaAtaqueAZombies* _estrategiaAtaqueAZombies)
{

	EstrategiaAtaque = Cast<IEstrategiaAtaqueAZombies>(_estrategiaAtaqueAZombies);

	// Log Error if the cast failed
	if (!EstrategiaAtaque)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("Invalid Cast! See Output log for more details"));
		UE_LOG(LogTemp, Error, TEXT("Moverse(): The Actor is not a estrategia de movimiento! Are you sure that the Actor implements that interface? "));
	}

}

void APlant::atacar(const FVector& TargetLocation)
{
	EstrategiaAtaque->atacarA(this, FVector(0.0f,1.0f,0.0f));

}



