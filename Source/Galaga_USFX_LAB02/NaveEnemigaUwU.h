// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaUwU.generated.h"


UCLASS()

class GALAGA_USFX_LAB02_API ANaveEnemigaUwU : public ANaveEnemiga
{
	GENERATED_BODY()





public:
	ANaveEnemigaUwU();
public:
	virtual void Tick(float DeltaTime) override;
public:
	virtual void Mover(float DeltaTime);
	float Radio = 50.0f; // Radio de la circunferencia
	float Angulo = 0.0f; // Ángulo inicial
	float Speed = 20.0f; // Velocidad de rotación
	
};
