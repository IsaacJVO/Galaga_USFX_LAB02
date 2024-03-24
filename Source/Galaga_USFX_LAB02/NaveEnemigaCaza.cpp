// Fill out your copyright notice in the Description page of Project Settings.
#include "NaveEnemigaCaza.h"

ANaveEnemigaCaza::ANaveEnemigaCaza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);

	// Set this actor to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;

	// Set a default movement speed
	VelocidadMovimiento = 100.0f; // unidades por segundo

	DireccionMovimientoVertical = -1;
}

void ANaveEnemigaCaza::BeginPlay()
{
	Super::BeginPlay();
}

/*void ANaveEnemigaCaza::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	//Mover(DeltaTime);

	//Código sin tick**********
	//float Desplazamiento = movimiento * DeltaTime;

	// Mover el objeto en la dirección deseada
	//Objeto->SetLocation(Objeto->GetLocation() + Desplazamiento);

	 // Mover el actor en el eje X a una velocidad constante

	float x = 0.0f;
	float y = VelocidadMovimiento * DeltaTime;
	float z = 0.0f;
	float aux = 0.0f;
	FVector NuevaPosicion;
	//for (int i = 0; i < 6; i++) {
		
	NuevaPosicion = GetActorLocation() + FVector(x, y, z);
		if(NuevaPosicion.Y <= 1528.0f)
				SetActorLocation(NuevaPosicion);

		x = x - 300.0f;
		y = VelocidadMovimiento * -DeltaTime;
		if(NuevaPosicion.Y >= -1600.0f) {
			
			SetActorLocation(NuevaPosicion);
		}
	//}
	
}*/



void ANaveEnemigaCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Definir la velocidad de movimiento vertical
	float VelocidadVertical = 700.0f; // Puedes ajustar esta velocidad según sea necesario

	// Calcular el desplazamiento vertical para este fotograma
	float DesplazamientoVertical = VelocidadVertical * DeltaTime;

	// Obtener la posición actual de la nave
	FVector PosicionActual = GetActorLocation();

	// Definir los límites superior e inferior de movimiento
	float LimiteSuperior = 1528.0f;
	float LimiteInferior = -1600.0f;

	// Verificar si la nave está moviéndose hacia arriba o hacia abajo
	if (DireccionMovimientoVertical == 1) // Movimiento hacia arriba
	{
		// Mover la nave hacia arriba
		FVector NuevaPosicion = PosicionActual + FVector(0.0f, DesplazamientoVertical, 0.0f);
		if (NuevaPosicion.Y <= LimiteSuperior)
		{
			SetActorLocation(NuevaPosicion);
		}
		else
		{
			// Si alcanza el límite superior, cambiar la dirección de movimiento a hacia abajo
			DireccionMovimientoVertical = -1;
		}
	}
	else // Movimiento hacia abajo
	{
		// Mover la nave hacia abajo
		FVector NuevaPosicion = PosicionActual - FVector(0.0f, DesplazamientoVertical, 0.0f);
		if (NuevaPosicion.Y >= LimiteInferior)
		{
			SetActorLocation(NuevaPosicion);
		}
		else
		{
			// Si alcanza el límite inferior, cambiar la dirección de movimiento a hacia arriba
			DireccionMovimientoVertical = 1;
		}
	}
}



void ANaveEnemigaCaza::Mover(float DeltaTime)
{
	FVector PosicionActual = GetActorLocation();

	float NuevaX = FMath::RandRange(-1000.0f, 1000.0f) * DeltaTime;
	float NuevaY = FMath::RandRange(-1000.0f, 1000.0f) * DeltaTime;

	FVector NuevaPosicion = FVector(PosicionActual.X + NuevaX, PosicionActual.Y + NuevaY, PosicionActual.Z);

	SetActorLocation(NuevaPosicion);
}
