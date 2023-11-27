// Fill out your copyright notice in the Description page of Project Settings.
#include "Zombie.h"

#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Plant.h"

#include "Projectile.h"

// Sets default values
AZombie::AZombie()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Tube.Shape_Tube'"));
	ZombieMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlantMesh"));
	ZombieMeshComponent->SetStaticMesh(ZombieMesh.Object);
	//ZombieMeshComponent->SetRelativeScale3D(FVector(0.15f, 0.15f, 0.35f));
	ZombieMeshComponent->SetRelativeScale3D(FVector(0.35f, 0.35f, 0.55f));

	RootComponent = ZombieMeshComponent;

	ZombieMeshComponent->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	ZombieMeshComponent->SetSimulatePhysics(true);
	//ZombieMeshComponent->OnComponentBeginOverlap.AddDynamic(this, &AZombie::OnOverlapBeginFunction);		// set up a notification for when this component hits something

	RootComponent = ZombieMeshComponent;

	// Asignar la función de evento a OnOverlapBegin del componente de colisión

	//ZombieMeshComponent->OnComponentHit.AddDynamic(this, &AZombie::OnHit);		// set up a notification for when this component hits something
	ZombieMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	Energia = 200;
	Velocidad = 100;
	Tags.Add(TEXT("Zombie"));

	DamageGenerates = 10.0f;
	//Health = 100.0f;
	MovementSpeed = 0.10f;
	bCanMove = false;
}

// Called when the game starts or when spawned
void AZombie::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AZombie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector LocalizacionObjetivo = FVector(-250.0f, -440.0f, 25.0f);
	FVector Direccion = LocalizacionObjetivo - FVector(-250.0f, 490.0f, 25.0f);
	float DistanciaAlObjetivo = FVector::Dist(LocalizacionObjetivo, this->GetActorLocation());

	float DeltaMove = Velocidad * GetWorld()->DeltaTimeSeconds;

	if (DeltaMove > DistanciaAlObjetivo)
	{
		this->SetActorLocation(LocalizacionObjetivo);
	}
	else
	{
		this->AddActorWorldOffset(Direccion * DeltaMove);
	}

	CurrentLocation = GetActorLocation();
}

void AZombie::morir()
{
	Destroy();			//El actor se destruye
	this->Destroy();		//El actor también se destruye
	SetActorHiddenInGame(true);	//El actor sólo desaparece
}

float AZombie::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	// Aquí puedes manejar el daño como desees, por ejemplo, actualizando la salud del actor.
//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Health Zombie: %f"), this->Health));

	Health -= Damage;
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Health Zombie: %f"), this->Health));
	// Devuelve la cantidad de daño que se aplicó realmente.
	return Health;
}

void AZombie::MoveToTarget(FVector TargetLocation)
{
	FVector Direction = TargetLocation - GetActorLocation();
	float DistanceToTarget = FVector::Dist(TargetLocation, GetActorLocation());

	float DeltaMove = MovementSpeed * GetWorld()->DeltaTimeSeconds;

	if (DeltaMove > DistanceToTarget)
	{
		// Si el desplazamiento excede la distancia al objetivo, mueve directamente al objetivo
		SetActorLocation(TargetLocation);
	}
	else
	{
		// Mueve el objeto en la dirección calculada
		AddActorWorldOffset(Direction.GetSafeNormal() * DeltaMove);
	}
}
void AZombie::Destroyed()
{
	FString nombreZombie = this->GetName();
}

void AZombie::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{

	//Destroy();
	AProjectile* proyectil = Cast<AProjectile>(Other);

	if (Other != proyectil) {
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Este es un mensaje")));
		Other->Destroy();
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Nombre del otro actor: %s"), *Other->GetName()));

	}
	//Destroy();
	/*GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Este es un mensaje")));
	Other->Destroy();*/
}

bool AZombie::IsActorDestroyed() const
{
	return IsPendingKill();
}

void AZombie::notificarPocisionZombie(APublicador* Publicador)
{
	// Obtener la posición actual del zombie y notificar a las plantas
	FVector PosicionZombie = GetActorLocation();
	if (PosicionZombie.Y == 0)
	{
		// Obtener el publicador específico (en este caso ANotificarPlantas)
		ANotificarPlantas* NotificadorPlantas = Cast<ANotificarPlantas>(Publicador);
		if (NotificadorPlantas)
		{
			// Notificar a las plantas sobre la posición del zombie
			NotificadorPlantas->establecerPocisionZombie(FString::Printf(TEXT("Zombie en Y=0: %s"), *GetName()));
		}
	}
}




