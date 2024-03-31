#include "NaveEnemiga.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "TimerManager.h"
#include "AComponenteMovimiento.h"
#include "ProyectilEnemiga.h"

ANaveEnemiga::ANaveEnemiga()
{
	PrimaryActorTick.bCanEverTick = true;

	mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	mallaNaveEnemiga->SetupAttachment(RootComponent);
	RootComponent = mallaNaveEnemiga;

	MovimientoNavesComponent = CreateDefaultSubobject<UAComponenteMovimiento>(TEXT("MovimientoNavesComponente"));
}

void ANaveEnemiga::BeginPlay()
{
	Super::BeginPlay();

	// Inicializar la posición inicial
	PosicionInicial = GetActorLocation();
}

void ANaveEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Actualizar el ángulo para el movimiento
	Angulo += Speed * DeltaTime;

	// Calcular la nueva posición basada en el ángulo y la velocidad
	float NuevaX = GetActorLocation().X + Radio * FMath::Cos(Angulo) * DeltaTime;
	FVector NewLocation = FVector(NuevaX, GetActorLocation().Y, GetActorLocation().Z);
	SetActorLocation(NewLocation);

	// Actualizar el tick del componente de movimiento
	MovimientoNavesComponent->TickComponent(DeltaTime, ELevelTick::LEVELTICK_TimeOnly, nullptr);
}




