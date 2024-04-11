// Fill out your copyright notice in the Description page of Project Settings.
#include "NaveEnemigaEspia.h"


ANaveEnemigaEspia::ANaveEnemigaEspia()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_4.TwinStickUFO_4'"));
    mallaNaveEnemiga->SetStaticMesh(malla.Object);
    PrimaryActorTick.bCanEverTick = true;


}

void ANaveEnemigaEspia::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
 
}

void ANaveEnemigaEspia::Mover(float DeltaTime)
{
	
}