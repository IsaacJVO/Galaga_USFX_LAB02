
#include "ProyectilEnemiga.h"

AProyectilEnemiga::AProyectilEnemiga()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile"));

	PrimaryActorTick.bCanEverTick = true;

}

void AProyectilEnemiga::BeginPlay()
{
	Super::BeginPlay();
	
}

void AProyectilEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

