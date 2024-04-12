#include "AComponenteInvisible.h"

UAComponenteInvisible::UAComponenteInvisible()
{

	PrimaryComponentTick.bCanEverTick = true;

	
}


void UAComponenteInvisible::BeginPlay()
{
	Super::BeginPlay();


	Malla = Cast<UStaticMeshComponent>(GetOwner()->GetComponentByClass(UStaticMeshComponent::StaticClass()));  

	GetWorld()->GetTimerManager().SetTimer(TiempoVisibilidad, this, &UAComponenteInvisible::AparecerDesaparecerNaves, 5.0f, true); //cada 5 segundos

	
}


// Called every frame
void UAComponenteInvisible::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

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

