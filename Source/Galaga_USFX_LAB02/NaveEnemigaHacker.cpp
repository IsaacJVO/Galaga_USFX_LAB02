
#include "NaveEnemigaHacker.h"

ANaveEnemigaHacker::ANaveEnemigaHacker()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_5.TwinStickUFO_5'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);
	nombre = "NaveEnemigaHacker";
	PrimaryActorTick.bCanEverTick = true;
}

void ANaveEnemigaHacker::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);

}

void ANaveEnemigaHacker::Mover(float DeltaTime)
{
	Mover(DeltaTime);
}

