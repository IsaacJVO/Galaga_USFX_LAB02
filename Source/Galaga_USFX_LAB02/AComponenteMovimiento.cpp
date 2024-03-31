// Fill out your copyright notice in the Description page of Project Settings.


#include "AComponenteMovimiento.h"

// Sets default values for this component's properties
UAComponenteMovimiento::UAComponenteMovimiento()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAComponenteMovimiento::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


//OPCION 1
void UAComponenteMovimiento::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    AActor* Parent = GetOwner();
    if (Parent)
    {
        // Obtener la posición actual de la nave
        FVector PosicionActual = Parent->GetActorLocation();

        // Definir los límite DERECHO E IZQUIERDO de movimiento
        float LimiteDerecho = 1528.0f;
        float LimiteIzquierdo = -1600.0f;

        // Definir la velocidad de movimiento horizontal
        float VelocidadHorizontal =150.0f;

        // Calcular el desplazamiento horizontal para este fotograma
        float DesplazamientoHorizontal = VelocidadHorizontal * DeltaTime;

        // Verificar si la nave está moviéndose hacia derecha o izquierda

        if (DireccionMovimientoHorizontal == 1) // Movimiento hacia derecha
        {
            // Mover la nave hacia derecha
            FVector NuevaPosicion = PosicionActual + FVector(0.0f, DesplazamientoHorizontal, 0.0f);
            if (NuevaPosicion.Y <= LimiteDerecho)
            {
                Parent->SetActorLocation(NuevaPosicion);
            }
            else
            {
                // Si alcanza el límite superior, cambiar la dirección de movimiento a hacia izquierda
                DireccionMovimientoHorizontal = -1;
            }
        }
        else // Movimiento hacia izquierda
        {
            // Mover la nave hacia izquierda
            FVector NuevaPosicion = PosicionActual - FVector(0.0f, DesplazamientoHorizontal, 0.0f);
            if (NuevaPosicion.Y >= LimiteIzquierdo)
            {
                Parent->SetActorLocation(NuevaPosicion);
            }
            else
            {
                // Si alcanza el límite de la izquierda, cambiar la dirección de movimiento a hacia la derecha
                DireccionMovimientoHorizontal = 1;
            }
        }
    }
}

//OPCION 2

/*void UAComponenteMovimiento::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	AActor* Parent = GetOwner();
	if (Parent)
	{
		// Get the current location of the owner
		//encuentra la posicion actual del AActor
		FVector CurrentLocation = Parent->GetActorLocation();

		float MovimientoY = MovimientoNaves * DeltaTime;

		// Calculate the new position based on the movement speed
		//Calcula la nueva posicion basada en la velocidad de movimiento(Y hacia la Izquierda)
		FVector NewLocation = FVector(CurrentLocation.X, CurrentLocation.Y + MovimientoNaves, CurrentLocation.Z);
		// Muestra  la nueva position
		Parent->SetActorLocation(NewLocation);

		//Limite del mapa
		if (NewLocation.Y > limiteInferiorY)// 1600.0f
		{
			Parent->SetActorLocation(FVector(CurrentLocation.X, -1600.0f, CurrentLocation.Z));

		}


	}
}*/

