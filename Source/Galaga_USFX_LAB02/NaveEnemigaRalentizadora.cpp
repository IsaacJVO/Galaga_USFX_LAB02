// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaRalentizadora.h"

ANaveEnemigaRalentizadora::ANaveEnemigaRalentizadora()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_6.TwinStickUFO_6'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);

	// Set this actor to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;
}

void ANaveEnemigaRalentizadora::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaRalentizadora::Mover(float DeltaTime)
{
}
