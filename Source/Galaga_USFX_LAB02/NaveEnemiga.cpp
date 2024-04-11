#include "NaveEnemiga.h"


ANaveEnemiga::ANaveEnemiga()
{

	PrimaryActorTick.bCanEverTick = true;

	mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	mallaNaveEnemiga->SetupAttachment(RootComponent);
	RootComponent = mallaNaveEnemiga;

	MovimientoNavesComponent = CreateDefaultSubobject<UAComponenteMovimiento>(TEXT("MovimientoNavesComponente"));
	MovimientoNavesComponent->PrimaryComponentTick.bCanEverTick = true;


	//InvisibleComponent = CreateDefaultSubobject<UAComponenteInvisible>(TEXT("InvisibleComponent")); 
	//InvisibleComponent->PrimaryComponentTick.bCanEverTick = true;

}

void ANaveEnemiga::BeginPlay()
{
	Super::BeginPlay(); // Llamamos a la implementación de BeginPlay de la clase base

	// No hay acciones adicionales en BeginPlay en este momento
}

void ANaveEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Angulo += Speed * DeltaTime;
	
	//// Calcula las nuevas posiciones en x y y
	float NuevaX = GetActorLocation().X + Radio * FMath::Cos(Angulo) * DeltaTime;
	float NuevaY = GetActorLocation().Y + Radio * FMath::Sin(Angulo) * DeltaTime;

	//// Establece la nueva posición
	FVector NewLocation = FVector(NuevaX, NuevaY, GetActorLocation().Z);
	SetActorLocation(NewLocation);

	MovimientoNavesComponent->TickComponent(DeltaTime, ELevelTick::LEVELTICK_TimeOnly, nullptr);
}





