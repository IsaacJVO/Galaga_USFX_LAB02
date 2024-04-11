// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaTitan.h"

ANaveEnemigaTitan::ANaveEnemigaTitan()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshFinder(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_8.TwinStickUFO_8'"));
    if (MeshFinder.Succeeded())
    {
        mallaNaveEnemiga->SetStaticMesh(MeshFinder.Object);

        // Escalar la malla
        FVector Escala = FVector(3.0f, 3.0f, 3.0f); // Escalar por un factor de 3 en todas las direcciones
        mallaNaveEnemiga->SetWorldScale3D(Escala);
    }
        // Set this actor to call Tick() every frame
        PrimaryActorTick.bCanEverTick = true;
}

void ANaveEnemigaTitan::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
        Mover(DeltaTime);

            // Definir la velocidad de movimiento vertical
            float VelocidadVertical = 250.0f; // Puedes ajustar esta velocidad seg�n sea necesario

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


void ANaveEnemigaTitan::Mover(float DeltaTime)
{
    // Actualizar el �ngulo para el movimiento
    Angulo += Speed * DeltaTime; 

// Calcular la nueva posici�n basada en el �ngulo y la velocidad
    float NuevaX = GetActorLocation().X + Radio * FMath::Cos(Angulo) * DeltaTime; 
    FVector NewLocation = FVector(NuevaX, GetActorLocation().Y, GetActorLocation().Z); 
    SetActorLocation(NewLocation); 

}
