// Fill out your copyright notice in the Description page of Project Settings.
#include "NaveEnemigaEspia.h"


ANaveEnemigaEspia::ANaveEnemigaEspia()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));
    mallaNaveEnemiga->SetStaticMesh(malla.Object);
    PrimaryActorTick.bCanEverTick = true;

    DireccionMovimientoVertical = -1;

}

void ANaveEnemigaEspia::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
 
}

void ANaveEnemigaEspia::Mover(float DeltaTime)
{
	
}