// Fill out your copyright notice in the Description page of Project Settings.
#include "Zombie.h"

#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Estrategy_AtaqPVZL01GameModeBase.h"
#include "Engine/World.h"
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
	ZombieMeshComponent->SetRelativeScale3D(FVector(0.25f, 0.25f, 0.45f));

	RootComponent = ZombieMeshComponent;

	ZombieMeshComponent->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	ZombieMeshComponent->SetSimulatePhysics(true);
	//ZombieMeshComponent->OnComponentBeginOverlap.AddDynamic(this, &AZombie::OnOverlapBeginFunction);		// set up a notification for when this component hits something

	RootComponent = ZombieMeshComponent;

	// Asignar la funci�n de evento a OnOverlapBegin del componente de colisi�n

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

	//notifPocisionASuscriptores();

	AEstrategy_AtaqPVZL01GameModeBase* GameMode = Cast<AEstrategy_AtaqPVZL01GameModeBase>(UGameplayStatics::GetGameMode(this));
	if (GameMode)
	{
		plantasSuscriptores = GameMode->GetPlantArray();
		// Ahora puedes manipular PlantArray
	}


	notifPocisionASuscriptores();
}

void AZombie::morir()
{
	Destroy();			//El actor se destruye
	this->Destroy();		//El actor tambi�n se destruye
	SetActorHiddenInGame(true);	//El actor s�lo desaparece
}

float AZombie::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	// Aqu� puedes manejar el da�o como desees, por ejemplo, actualizando la salud del actor.
//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Health Zombie: %f"), this->Health));

	Health -= Damage;
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Health Zombie: %f"), this->Health));
	// Devuelve la cantidad de da�o que se aplic� realmente.
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
		// Mueve el objeto en la direcci�n calculada
		AddActorWorldOffset(Direction.GetSafeNormal() * DeltaMove);
	}

}
void AZombie::Destroyed()
{
	FString nombreZombie = this->GetName();
}

void AZombie::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	AProjectile* proyectil = Cast<AProjectile>(Other);

	if (Other != proyectil) {
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Este es un mensaje")));
		Other->Destroy();
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Nombre del otro actor: %s"), *Other->GetName()));

	}
}

bool AZombie::IsActorDestroyed() const
{
	return IsPendingKill();
}

void AZombie::Suscribirse(APlant* _Suscriptor)
{
	plantasSuscriptores.Add(_Suscriptor);
}

void AZombie::Desuscribirse(APlant* _SuscriptorAQuitar)
{
	plantasSuscriptores.Remove(_SuscriptorAQuitar);
}

void AZombie::notifPocisionASuscriptores() {

	//PosicionActualZombie = GetActorLocation();

	//if (PosicionActualZombie.Y < 400) {
	//	GEngine->AddOnScreenDebugMessage(-1, 0.50f, FColor::Red, TEXT("Que disparen las plantas"));// , false, FVector2D(2.f, 3.f));
	//		//GEngine->AddOnScreenDebugMessage(-2, 5.f, FColor::Red, TEXT("Planta ha sido notificada"), false, FVector2D(7.f, 7.f));
	//}if (PosicionActualZombie.Y < -160.0f) {

	//	GEngine->AddOnScreenDebugMessage(-1, 0.4f, FColor::Yellow, TEXT("Enta en Accion Apisonaflor"));// , false, FVector2D(3.f, 2.f));
	//		//GEngine->AddOnScreenDebugMessage(-2, 5.f, FColor::Red, TEXT("Planta ha sido notificada"), false, FVector2D(7.f, 7.f));
	//}
	//// Bucle para cada suscriptor (en este caso, plantas suscriptoras)
	//for (APlant* Planta : plantasSuscriptores)
	//{
	//	// Aseg�rate de que la planta es un suscriptor v�lido
	//	ISuscriptor* Sus = Cast<ISuscriptor>(Planta);

	//	if (Sus)
	//	{
	//		// Notifica a cada planta que algo ha cambiado, para que puedan ejecutar su propia rutina
	//		Sus->notificarPocision(this);
	//	}
	//}

	PosicionActualZombie = GetActorLocation();
	if (PosicionActualZombie.Y < 380.0f) {

		for (int32 i = 0; i < plantasSuscriptores.Num(); i++)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("Que disparen las plantas"));//, false, FVector2D(2.f, 3.f));
			//GEngine->AddOnScreenDebugMessage(-2, 5.f, FColor::Red, TEXT("Planta ha sido notificada"), false, FVector2D(7.f, 7.f));
			plantasSuscriptores[i]->_HsidoNotificado = true;
		}
	}if (PosicionActualZombie.Y <= -160.0f) {

		for (int32 i = 0; i < plantasSuscriptores.Num(); i++)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, TEXT("Enta en Accion Apisonaflor"), false, FVector2D(3.f, 2.f));
			//GEngine->AddOnScreenDebugMessage(-2, 5.f, FColor::Red, TEXT("Planta ha sido notificada"), false, FVector2D(7.f, 7.f));
			plantasSuscriptores[i]->_HsidoNotificado2 = true;

		}
	}if (PosicionActualZombie.Y < 100.0f) {

		for (int32 i = 0; i < plantasSuscriptores.Num(); i++)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, TEXT("Disparo otra vez "), false, FVector2D(3.f, 2.f));
			//GEngine->AddOnScreenDebugMessage(-2, 5.f, FColor::Red, TEXT("Planta ha sido notificada"), false, FVector2D(7.f, 7.f));
			plantasSuscriptores[i]->_HsidoNotificado3 = true;

		}
	}
}
