// Fill out your copyright notice in the Description page of Project Settings.
#include "NaveEnemigaTransporte.h"

ANaveEnemigaTransporte::ANaveEnemigaTransporte()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);

	PrimaryActorTick.bCanEverTick = true;

	VelocidadMovimiento = 100.0f; 

	DireccionMovimientoVertical = -1;
}

void ANaveEnemigaTransporte::BeginPlay()
{
	Super::BeginPlay();
}

void ANaveEnemigaTransporte::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Definir la velocidad de movimiento vertical
    float VelocidadVertical = 700.0f; // Puedes ajustar esta velocidad seg�n sea necesario

    // Calcular el desplazamiento vertical para este fotograma
    float DesplazamientoVertical = VelocidadVertical * DeltaTime;

    // Obtener la posici�n actual de la nave
    FVector PosicionActual = GetActorLocation();

    // Definir los l�mites superior e inferior de movimiento
    float LimiteSuperior = 1528.0f;
    float LimiteInferior = -1600.0f;

    // Verificar si la nave est� movi�ndose hacia arriba o hacia abajo
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
            // Si alcanza el l�mite superior, cambiar la direcci�n de movimiento a hacia abajo
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
            // Si alcanza el l�mite inferior, cambiar la direcci�n de movimiento a hacia arriba
            DireccionMovimientoVertical = 1;
        }
    }
}

void ANaveEnemigaTransporte::Mover(float DeltaTime)
{
	FVector PosicionActual = GetActorLocation();

	float NuevaX = FMath::RandRange(-1000.0f, 1000.0f) * DeltaTime;
	float NuevaY = FMath::RandRange(-1000.0f, 1000.0f) * DeltaTime;

	FVector NuevaPosicion = FVector(PosicionActual.X + NuevaX, PosicionActual.Y + NuevaY, PosicionActual.Z);

	SetActorLocation(NuevaPosicion);
}
