// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombie.h"

#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Plant.h"
#include "PlantaObservador.h"

// Sets default values
AZombie::AZombie()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Tube.Shape_Tube'"));
	ZombieMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlantMesh"));
	ZombieMeshComponent->SetStaticMesh(ZombieMesh.Object);
	ZombieMeshComponent->SetRelativeScale3D(FVector(0.15f, 0.15f, 0.35f));

	RootComponent = ZombieMeshComponent;

	ZombieMeshComponent->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	ZombieMeshComponent->SetSimulatePhysics(true);
	ZombieMeshComponent->OnComponentBeginOverlap.AddDynamic(this, &AZombie::OnOverlapBeginFunction);		// set up a notification for when this component hits something

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

void AZombie::MoverZombie()
{
	UE_LOG(LogTemp, Warning, TEXT("Moviendo al Zombies"));
	if (GetActorLocation().Y < -140.0f )
	{
		//FVector PosicionActual = GetActorLocation();

		//for (auto& Observador : Observadores)
		//{
		//	if (Observador && Observador.GetObject())
		//	{
		//		IPlantaObservador* ObservadorPlanta = Cast<IPlantaObservador>(Observador.GetObject());
		//		if (ObservadorPlanta)
		//		{
		//			ObservadorPlanta->NotificadoPorZombie(PosicionActual);
		//		}
		//	}
		//}

		bHaNotificado = true;
	}
}

void AZombie::SuscribirPlanta(TScriptInterface<IPlantaObservador> Observador)
{
	if (Observador)
	{
		Observadores.AddUnique(Observador);
	}
}

void AZombie::DesuscribirPlanta(TScriptInterface<IPlantaObservador> Observador)
{
	Observadores.Remove(Observador);
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
		
	FVector LocalizacionObjetivo = FVector(-250.0f, -440.0f, 25.0f); // Cambia la ubicación objetivo según tus necesidades
	// Calcula la dirección y distancia al objetivo
	FVector Direccion = LocalizacionObjetivo - FVector(-250.0f, 100.0f, 25.0f);
	// Calcula la distancia de al objetivo
	float DistanciaAlObjetivo = FVector::Dist(LocalizacionObjetivo, this->GetActorLocation());

	// Calcula el desplazamiento en este frame
	float DeltaMove = Velocidad * GetWorld()->DeltaTimeSeconds;

	if (DeltaMove > DistanciaAlObjetivo)
	{
		// Si el desplazamiento excede la distancia al objetivo, mueve directamente al objetivo
		this->SetActorLocation(LocalizacionObjetivo);
		//this->SetActorRotation(NewRotation);
	}
	else
	{
		// Mueve el objeto en la dirección calculada
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

void AZombie::OnOverlapBeginFunction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OverlappedComponent != nullptr) && (OtherActor != this))
	{
		if (OtherActor->ActorHasTag("Plant"))
		{
			OtherActor->TakeDamage(DamageGenerates, FDamageEvent(), nullptr, this);
		}
		// Aquí puedes agregar más lógica para otras colisiones si es necesario.
	}
}

void AZombie::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Estamos aqui")));

		//OtherComp->AddImpulseAtLocation(GetVelocity() * 200.0f, GetActorLocation());
		if (OtherActor->ActorHasTag("Plant"))
		{
			//OtherComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
			

			OtherActor->TakeDamage(DamageGenerates, FDamageEvent(), nullptr, this);
			//OtherComp->DestroyComponent();
			//OtherActor->Destroy();
		}
		else
		{
			// Realiza acciones normales para la colisión con otros actores
			//OnHit(HitComp, OtherActor, OtherComp, NormalImpulse, Hit);
			//OtherComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

		}
	}
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

void AZombie::iniciarMovimiento()
{
	StartLocation = GetActorLocation();
	EndLocation = FVector(-250.0f, -440.0f, 25.0f);
}

