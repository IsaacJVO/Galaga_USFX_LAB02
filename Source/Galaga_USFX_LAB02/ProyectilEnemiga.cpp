// Fill out your copyright notice in the Description page of Project Settings.


#include "ProyectilEnemiga.h"

// Sets default values
AProyectilEnemiga::AProyectilEnemiga()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile"));

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProyectilEnemiga::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProyectilEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

