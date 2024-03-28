// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaHacker.h"

ANaveEnemigaHacker::ANaveEnemigaHacker()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Wedge_A.Shape_Wedge_A'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);
	nombre = "NaveEnemigaHacker";
	PrimaryActorTick.bCanEverTick = true;
}

void ANaveEnemigaHacker::BeginPlay()
{
	Super::BeginPlay();
}


void ANaveEnemigaHacker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);

	float VelocidadVertical = 300.0f;


	float DesplazamientoVertical = VelocidadVertical * DeltaTime;

	FVector PosicionActual = GetActorLocation();


	float LimiteSuperior = 1528.0f;
	float LimiteInferior = -1600.0f;


	if (DireccionMovimientoVertical == 1) // Movimiento hacia la Derecha
	{
		// Mover la nave hacia derecha
		FVector NuevaPosicion = PosicionActual + FVector(0.0f, DesplazamientoVertical, 0.0f);
		if (NuevaPosicion.Y <= LimiteSuperior)
		{
			SetActorLocation(NuevaPosicion);
		}
		else
		{

			DireccionMovimientoVertical = -1;
		}
	}
	else // Movimiento hacia izquirda
	{

		FVector NuevaPosicion = PosicionActual - FVector(0.0f, DesplazamientoVertical, 0.0f);
		if (NuevaPosicion.Y >= LimiteInferior)
		{
			SetActorLocation(NuevaPosicion);
		}
		else
		{
			// Si alcanza el límite inferior, cambiar la dirección de movimiento a hacia la izquierda
			DireccionMovimientoVertical = 1;
		}
	}
}

void ANaveEnemigaHacker::Mover(float DeltaTime)
{
	Angulo += Speed * DeltaTime;
	float NuevaX = GetActorLocation().X + Radio * FMath::Cos(Angulo) * DeltaTime;
	float NuevaY = GetActorLocation().Y + Radio * FMath::Sin(Angulo) * DeltaTime;

	FVector NewLocation = FVector(NuevaX, NuevaY, GetActorLocation().Z);
	SetActorLocation(NewLocation);

}

