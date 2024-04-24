// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaRalentizadora.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaUwU.h"
#include "NaveEnemigaHacker.h"
#include "GameFramework/Actor.h"
#include "NaveEnemigaFactory.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API ANaveEnemigaFactory : public AActor
{
	GENERATED_BODY()
	







public:
    static ANaveEnemiga* CrearNaveEnemiga(TSubclassOf<ANaveEnemiga> ClaseNave)
    {
        if (ClaseNave == ANaveEnemigaCaza::StaticClass())
        {
            return NewObject<ANaveEnemigaCaza>();
        }
        else if (ClaseNave == ANaveEnemigaTransporte::StaticClass())
        {
            return NewObject<ANaveEnemigaTransporte>();
        }
        else if (ClaseNave == ANaveEnemigaRalentizadora::StaticClass())
        {
			return NewObject<ANaveEnemigaRalentizadora>();
		}
        else if (ClaseNave == ANaveEnemigaEspia::StaticClass())
        {
			return NewObject<ANaveEnemigaEspia>();
		}
        else if (ClaseNave == ANaveEnemigaUwU::StaticClass())
        {
			return NewObject<ANaveEnemigaUwU>();
		}
		else if (ClaseNave == ANaveEnemigaHacker::StaticClass())
		{
            return NewObject<ANaveEnemigaHacker>();
        }

        // Si no se reconoce la clase, devuelve una instancia genérica de ANaveEnemiga
        return NewObject<ANaveEnemiga>();
    }


public:	
	// Sets default values for this actor's properties
	ANaveEnemigaFactory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
