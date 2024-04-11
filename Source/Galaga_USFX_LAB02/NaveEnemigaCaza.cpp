// Fill out your copyright notice in the Description page of Project Settings.
#include "NaveEnemigaCaza.h"

ANaveEnemigaCaza::ANaveEnemigaCaza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_2.TwinStickUFO_2'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);

	// Set this actor to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;

}

void ANaveEnemigaCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
	
}

void ANaveEnemigaCaza::Mover(float DeltaTime)
{

}
