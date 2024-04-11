// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaRalentizadora.generated.h"


UCLASS()

class GALAGA_USFX_LAB02_API ANaveEnemigaRalentizadora : public ANaveEnemiga
{
	GENERATED_BODY()







	
public:
	ANaveEnemigaRalentizadora();
public:
	virtual void Tick(float DeltaTime) override;
public:
	virtual void Mover(float DeltaTime);

//private:
//	int DireccionMovimientoVertical;
//
//private:
//	float VelocidadMovimiento;

};
