// Fill out your copyright notice in the Description page of Project Settings.


#include "Plant.h"
#include "Projectile.h"
#include "Zombie.h"
#include "EstrategiaAtaqueDisparo.h"

// Sets default values
APlant::APlant()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlantaMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	MeshPlanta = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlantMesh"));
	MeshPlanta->SetStaticMesh(PlantaMesh.Object);
	MeshPlanta->SetRelativeScale3D(FVector(0.15f, 0.15f, 0.35f));

	RootComponent = MeshPlanta;

	MeshPlanta->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	MeshPlanta->SetSimulatePhysics(false);
	MeshPlanta->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);


	//bCanFire = true;
	//GunOffset = FVector(90.f, 0.f, 0.f);
	//FireRate = 0.2f;

	////Energia = 200;
	//TiempoTranscurrido = 0.0f;
	//TiempoEntreDisparos = 1.0f;
}

// Called when the game starts or when spawned
void APlant::BeginPlay()
{
	Super::BeginPlay();
	AEstrategiaAtaqueDisparo* EstrategiaAtaqueDisparo =  GetWorld()->SpawnActor<AEstrategiaAtaqueDisparo>(AEstrategiaAtaqueDisparo::StaticClass());
	setEstrategiaAtaqueAZombies(EstrategiaAtaqueDisparo);

}

// Called every frame
void APlant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//if (Health <= 0)
	//{
	//	Destroy();
	//}
	//TiempoTranscurrido += DeltaTime;
	//if (TiempoTranscurrido >= TiempoEntreDisparos) {

	//	FireShot(FVector(0.0f, 1.0f, 0.0f));
	//	TiempoTranscurrido = 0.0f;
	//}
}

void APlant::setEstrategiaAtaqueAZombies(AActor* _EstrategiaAtaqueAZombies)
{

	EstrategiaAtaque = Cast<IEstrategiaAtaqueAZombies>(_EstrategiaAtaqueAZombies);

	//Log Error if the cast failed
	if (!EstrategiaAtaque)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("Invalid Cast! See Output log for more details"));
		UE_LOG(LogTemp, Error, TEXT("Moverse(): The Actor is not a estrategia de movimiento!Are you sure that the Actor implements that interface ? "));
	}


}

void APlant::disparar()
{


	EstrategiaAtaque ->atacarA(this, FVector(0.0f, 1.0f, 0.0f));



}

//
//float APlant::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
//{
//	// Aquí puedes manejar el daño como desees, por ejemplo, actualizando la salud del actor.
//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Health Zombie: %f"), this->Health));
//
//	Health -= Damage;
//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Health Zombie: %f"), this->Health));
//
//	// Devuelve la cantidad de daño que se aplicó realmente.
//	return Health;
//}
//
//void APlant::NotifyActorBeginOverlap(AActor* OtherActor)
//{
//	AZombie* Zombie = Cast<AZombie>(OtherActor);
//	if (Zombie)
//	{
//		if (NombrePlantas != "Hipnoseta")
//		{
//			Zombie->Destroy();
//			this->Destroy();
//		}
//		else
//		{
//			Zombie->SetMovingX(10);
//			this->Destroy();
//		}
//	}
//}
//
//
