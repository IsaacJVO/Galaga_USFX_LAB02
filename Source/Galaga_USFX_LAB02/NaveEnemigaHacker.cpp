// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaHacker.h"

ANaveEnemigaHacker::ANaveEnemigaHacker()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Wedge_A.Shape_Wedge_A'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);
	nombre = "NaveEnemigaHacker";
	PrimaryActorTick.bCanEverTick = true;
}

void ANaveEnemigaHacker::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaHacker::Mover(float DeltaTime)
{

}

