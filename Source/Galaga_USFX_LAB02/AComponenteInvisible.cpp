// Fill out your copyright notice in the Description page of Project Settings.


#include "AComponenteInvisible.h"

// Sets default values for this component's properties
UAComponenteInvisible::UAComponenteInvisible()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAComponenteInvisible::BeginPlay()
{
	Super::BeginPlay();

	// ...
	// Obtener la malla de la nave
	Malla = Cast<UStaticMeshComponent>(GetOwner()->GetComponentByClass(UStaticMeshComponent::StaticClass()));  

	GetWorld()->GetTimerManager().SetTimer(TiempoVisibilidad, this, &UAComponenteInvisible::AparecerDesaparecerNaves, 5.0f, true); //cada 5 segundos

	
}


// Called every frame
void UAComponenteInvisible::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAComponenteInvisible::AparecerDesaparecerNaves()
{
	if (Malla)//verificar
	{
		// Decide aleatoriamente si la nave debe ser invisible
		bool Desaparecer = FMath::RandBool();

		// Cambia la visibilidad de la malla aleatoriamente
		Malla->SetVisibility(!Desaparecer);
	}
}

