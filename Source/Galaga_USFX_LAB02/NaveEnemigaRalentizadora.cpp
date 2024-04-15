
#include "NaveEnemigaRalentizadora.h"

ANaveEnemigaRalentizadora::ANaveEnemigaRalentizadora()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_6.TwinStickUFO_6'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);

	PrimaryActorTick.bCanEverTick = true;
}

void ANaveEnemigaRalentizadora::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANaveEnemigaRalentizadora::Mover(float DeltaTime)
{
}
