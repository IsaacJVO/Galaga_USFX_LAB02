
#include "NaveEnemigaUwU.h"

ANaveEnemigaUwU::ANaveEnemigaUwU()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_7.TwinStickUFO_7'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);

	PrimaryActorTick.bCanEverTick = true;
}

void ANaveEnemigaUwU::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANaveEnemigaUwU::Mover(float DeltaTime)
{
}
