// Fill out your copyright notice in the Description page of Project Settings.


#include "AComponenteMovimiento.h"

// Sets default values for this component's properties
UAComponenteMovimiento::UAComponenteMovimiento()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UAComponenteMovimiento::BeginPlay()
{
	Super::BeginPlay();
	
}


//OPCION 1
void UAComponenteMovimiento::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    AActor* Parent = GetOwner();
    if (Parent)
    {
        FVector PosicionActual = Parent->GetActorLocation();

        float LimiteDerecho = 1600.0f;
        float LimiteIzquierdo = -1600.0f;

        float VelocidadHorizontal = 300.0f;

        float DesplazamientoHorizontal = VelocidadHorizontal * DeltaTime;

  

        if (DireccionMovimientoHorizontal == 1) 
        {
            // Mover la nave hacia derecha
            FVector NuevaPosicion = PosicionActual + FVector(0.0f, DesplazamientoHorizontal, 0.0f);
            if (NuevaPosicion.Y <= LimiteDerecho)
            {
                Parent->SetActorLocation(NuevaPosicion);
            }
            else
            {
                DireccionMovimientoHorizontal = -1;
            }
        }
        else 
        {
            FVector NuevaPosicion = PosicionActual - FVector(0.0f, DesplazamientoHorizontal, 0.0f);
            if (NuevaPosicion.Y >= LimiteIzquierdo)
            {
                Parent->SetActorLocation(NuevaPosicion);
            }
            else
            {
                DireccionMovimientoHorizontal = 1;
            }
        }
    }

    Angulo += Speed * DeltaTime;

    float NuevaX = GetOwner()->GetActorLocation().X + Radio * FMath::Cos(Angulo) * DeltaTime;
    float NuevaY = GetOwner()->GetActorLocation().Y + Radio * FMath::Sin(Angulo) * DeltaTime;

    FVector NewLocation = FVector(NuevaX, NuevaY, GetOwner()->GetActorLocation().Z);
    GetOwner()->SetActorLocation(NewLocation);
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

