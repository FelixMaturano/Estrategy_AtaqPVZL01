// Fill out your copyright notice in the Description page of Project Settings.


#include "Plant.h"
#include "Projectile.h"
#include "Zombie.h"
#include "EstrategiaAtaqueDisparo.h"
#include "EstrategiaAtaqueAZombies.h"
#include "EstrategiaAplastamientoAZ.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

#include "Suscriptor.h"


// Sets default values
APlant::APlant()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlantaMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	MeshPlanta = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlantMesh"));
	MeshPlanta->SetStaticMesh(PlantaMesh.Object);
	//MeshPlanta->SetRelativeScale3D(FVector(0.25f, 0.29f, 0.35f));
	MeshPlanta->SetRelativeScale3D(FVector(0.55f, 0.59f, 0.75f));

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

	EstrategiaPlanta = "atacar";

	//TiempoDemuestra = 0.0f;
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
	timerhandle += DeltaTime;

	Cambios();
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
void APlant::Destroyed()
{
	Notificador->Desuscribirse(this);
}
void APlant::notificarPocisionZombie(APublicador* Publicador)
{
	//Cambios();
}

void APlant::Cambios()
{

	atacar(LocalizacionObjetivo);

	if (timerhandle > 6)
	{
		for (int32 i = 0; i < Plantas.Num(); i++)
		{
			APlant* plantas = Cast<APlant>(Plantas[i]);
			if (plantas)
			{
				// Crear una nueva instancia de AEstrategiaAplastamientoAZ
				AEstrategiaAplastamientoAZ* NuevaEstrategia = GetWorld()->SpawnActor<AEstrategiaAplastamientoAZ>(AEstrategiaAplastamientoAZ::StaticClass());
				plantas->setEstrategiaAtaqueAZombies(NuevaEstrategia);
			}
		}
	}
	// Obtén la posición actual del zombie del Notificador
	FVector PosicionZombie = Notificador->GetPosicionZombie();

	if (PosicionZombie.Y== 0.0f)
	{
		EstrategiaPlanta == "EstrategiaAplastamientoAZ";

		// Cambia a la estrategia de ataque con disparo
		UE_LOG(LogTemp, Warning, TEXT("Zombie a la vista, cambia a la estrategia de ataque con disparo"));
		AEstrategiaAtaqueDisparo* EstrategiaDisparo = GetWorld()->SpawnActor<AEstrategiaAtaqueDisparo>(AEstrategiaAtaqueDisparo::StaticClass());
		setEstrategiaAtaqueAZombies(EstrategiaDisparo);

		// Inicializa LocalizacionObjetivo (ajústalo según tus necesidades)
		LocalizacionObjetivo = FVector(-250.0f, 490.0f, 25.0f);
	}
	 if (EstrategiaPlanta == "EstrategiaAplastamientoAZ")
	 {
	
		for (int32 i = 0; i < Plantas.Num(); i++)
		{
			APlant* plantas = Cast<APlant>(Plantas[i]);
			if (plantas)
			{
				// Crear una nueva instancia de AEstrategiaAplastamientoAZ
				AEstrategiaAplastamientoAZ* NuevaEstrategia = GetWorld()->SpawnActor<AEstrategiaAplastamientoAZ>(AEstrategiaAplastamientoAZ::StaticClass());
				plantas->setEstrategiaAtaqueAZombies(NuevaEstrategia);
			}
		}
	
	}if (EstrategiaPlanta == "EstategiaDisparo") {
	
		atacar(LocalizacionObjetivo);
	}

	// Realizar el ataque después de cambiar la estrategia
	
}

void APlant::DefinirNotificarPlantas(ANotificarPlantas* myNotificarPlantas)
{
	////Set the Clock Tower and Subscribe to that
	//Notificador = myNotificarPlantas;
	//Notificador->Suscribirse(this);
}
