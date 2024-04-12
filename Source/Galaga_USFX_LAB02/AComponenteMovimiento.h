#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AComponenteMovimiento.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GALAGA_USFX_LAB02_API UAComponenteMovimiento : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAComponenteMovimiento();
	
	
	UPROPERTY()

	float limiteInferiorY = 1600.0f;



protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	int DireccionMovimientoHorizontal = 1;

protected:
	float Radio = 500.0f; 
	float Angulo = 0.0f; 
	float Speed = 40.0f; 

		
};
