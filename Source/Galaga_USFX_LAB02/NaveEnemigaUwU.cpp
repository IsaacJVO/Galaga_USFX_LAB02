// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaUwU.h"

ANaveEnemigaUwU::ANaveEnemigaUwU()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_7.TwinStickUFO_7'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);

	// Set this actor to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;
}

void ANaveEnemigaUwU::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);	
}

void ANaveEnemigaUwU::Mover(float DeltaTime)
{
}
