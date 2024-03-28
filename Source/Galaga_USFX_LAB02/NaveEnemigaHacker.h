// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaHacker.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_LAB02_API ANaveEnemigaHacker : public ANaveEnemiga
{
	GENERATED_BODY()

	
public:
	ANaveEnemigaHacker();
public:
	virtual void Tick(float DeltaTime) override;

public:
	virtual void Mover(float DeltaTime);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	int DireccionMovimientoVertical;
private:
	float VelocidadMovimiento;
protected:
	float Radio = 700.0f;
	float Angulo = 0.0f;
	float Speed = 20.0F;

};
