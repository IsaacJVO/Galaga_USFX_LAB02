// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AComponenteMovimiento.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GALAGA_USFX_LAB02_API UAComponenteMovimiento : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAComponenteMovimiento();
	UPROPERTY()
	float MovimientoNaves = 4;
	float limiteInferiorY = -1600.0f;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


		
};
