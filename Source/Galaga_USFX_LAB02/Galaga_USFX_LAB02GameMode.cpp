// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_LAB02GameMode.h"
#include "Galaga_USFX_LAB02Pawn.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaHacker.h"



AGalaga_USFX_LAB02GameMode::AGalaga_USFX_LAB02GameMode()
{
    // set default pawn class to our character class
    DefaultPawnClass = AGalaga_USFX_LAB02Pawn::StaticClass();
}

void AGalaga_USFX_LAB02GameMode::BeginPlay()
{
    Super::BeginPlay();

    FVector ubicacionInicialNaves = FVector(550.0f, 500.0f, 200.0f);
    FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);

    UWorld* const World = GetWorld();
    if (World != nullptr)
    {
        FVector ubicacionActual = ubicacionInicialNaves;

        // Spawn de Naves Enemigas de tipo Caza
        for (int i = 0; i < 5; i++) {
            ubicacionActual = FVector(ubicacionInicialNaves.X, ubicacionInicialNaves.Y + 300.0f * (float)i, ubicacionInicialNaves.Z);
            ANaveEnemigaCaza* NaveEnemigaCazaActual = World->SpawnActor<ANaveEnemigaCaza>(ubicacionActual, rotacionNave);
            TANavesEnemigasCaza.Add(NaveEnemigaCazaActual);
        }

        // Resetear ubicación para Naves Enemigas de tipo Transporte
        ubicacionActual.X = ubicacionInicialNaves.X - 300.0f;

        // Spawn de Naves Enemigas de tipo Transporte
        for (int j = 0; j < 5; j++) {
            ubicacionActual.Y = ubicacionInicialNaves.Y + 300.0f * (float)j;
            ANaveEnemigaTransporte* NaveEnemigaTransporteActual = World->SpawnActor<ANaveEnemigaTransporte>(ubicacionActual, rotacionNave);
            TANavesEnemigasTransporte.Add(NaveEnemigaTransporteActual);
        }
        // Spawn de Naves Enemigas de tipo Espia
        ubicacionActual.X = ubicacionInicialNaves.X - 600.0f;
        for (int j = 0; j < 5; j++) {

            ubicacionActual.Y = ubicacionInicialNaves.Y + 300.0f * j;
            ANaveEnemigaEspia* NaveEnemigaEspiaActual = World->SpawnActor<ANaveEnemigaEspia>(ubicacionActual, rotacionNave);
            TANavesEnemigasEspia.Add(NaveEnemigaEspiaActual);
        }
        // Spawn de Naves Enemigas de tipo Hacker
        ubicacionActual.X = ubicacionInicialNaves.X - 900.0f;
        for (int j = 0; j < 5; j++) {

            ubicacionActual.Y = ubicacionInicialNaves.Y + 300.0f * j;
            ANaveEnemigaHacker* NaveEnemigaHackerActual = World->SpawnActor<ANaveEnemigaHacker>(ubicacionActual, rotacionNave);
            TANavesEnemigasHacker.Add(NaveEnemigaHackerActual);
        }
    }
}


