#include "NaveEnemiga.h"
#include "ProyectilEnemiga.h"


ANaveEnemiga::ANaveEnemiga()
{

	PrimaryActorTick.bCanEverTick = true;

	mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	mallaNaveEnemiga->SetupAttachment(RootComponent);
	RootComponent = mallaNaveEnemiga;

	MovimientoNavesComponent = CreateDefaultSubobject<UAComponenteMovimiento>(TEXT("MovimientoNavesComponente"));
	FireRate = 1.0f;
}

void ANaveEnemiga::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &ANaveEnemiga::FireProjectile, FireRate, true);

}

void ANaveEnemiga::FireProjectile()
{
	AProyectilEnemiga* Projectile = GetWorld()->SpawnActor<AProyectilEnemiga>(AProyectilEnemiga::StaticClass(), GetActorLocation(), GetActorRotation());
	if (Projectile)
	{
		// Obt�n la direcci�n hacia adelante de la nave enemiga
		FVector ForwardDirection = GetActorForwardVector();

		// Calcula la rotaci�n basada en la direcci�n hacia adelante
		FRotator SpawnRotation = ForwardDirection.Rotation();

		// Configura la posici�n y direcci�n del proyectil
		FVector SpawnLocation = GetActorLocation();
		Projectile->SetActorLocationAndRotation(SpawnLocation, SpawnRotation);

		// Dispara el proyectil
		Projectile->Fire();
	}
}

void ANaveEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 

	Angulo += Speed * DeltaTime; 

	float NuevaY = GetActorLocation().Y + Radio * FMath::Sin(Angulo) * DeltaTime; 

	FVector NewLocation = FVector(GetActorLocation().X, NuevaY, GetActorLocation().Z); 
	SetActorLocation(NewLocation); 
}





