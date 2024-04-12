#include "NaveEnemiga.h"


ANaveEnemiga::ANaveEnemiga()
{

	PrimaryActorTick.bCanEverTick = true;

	mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	mallaNaveEnemiga->SetupAttachment(RootComponent);
	RootComponent = mallaNaveEnemiga;

	MovimientoNavesComponent = CreateDefaultSubobject<UAComponenteMovimiento>(TEXT("MovimientoNavesComponente"));
	InvisibleComponent = CreateDefaultSubobject<UAComponenteInvisible>(TEXT("InvisibleComponent")); 
}

void ANaveEnemiga::BeginPlay()
{
	Super::BeginPlay();
}

void ANaveEnemiga::Tick(float DeltaTime)
{}





