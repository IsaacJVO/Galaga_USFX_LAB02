#include "Galaga_USFX_LAB02GameMode.h"
#include "Galaga_USFX_LAB02Pawn.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaHacker.h"
#include "NaveEnemigaUwU.h"
#include "NaveEnemigaRalentizadora.h"
#include "NaveEnemigaTitan.h"

// Constructor del GameMode
AGalaga_USFX_LAB02GameMode::AGalaga_USFX_LAB02GameMode()
{
    // Establece la clase predeterminada del Pawn
    DefaultPawnClass = AGalaga_USFX_LAB02Pawn::StaticClass();
}

// Función que se llama al iniciar el juego
void AGalaga_USFX_LAB02GameMode::BeginPlay()
{
    Super::BeginPlay();

    // Define la ubicación inicial para spawnear las naves enemigas
    FVector ubicacionInicialNaves = FVector(1000.0f, -1600.0f, 200.0f);
    FRotator rotacionNave = FRotator(0.0f, 180.0f, 0.0f);

    // Obtiene el mundo del juego
    UWorld* const World = GetWorld();
    if (World != nullptr)
    {
        // Spawn de Naves Enemigas de tipo Caza
        for (int i = 0; i < 6; i++) {
            // Calcula la ubicación actual para esta nave
            FVector ubicacionActual = FVector(ubicacionInicialNaves.X, ubicacionInicialNaves.Y + 300.0f * (float)i, ubicacionInicialNaves.Z);
            // Spawnea la nave enemiga de tipo Caza en la ubicación calculada
            ANaveEnemigaCaza* NaveEnemigaCazaActual = World->SpawnActor<ANaveEnemigaCaza>(ubicacionActual, rotacionNave);
            // Agrega la nave enemiga a un contenedor
            TANavesEnemigasCaza.Add(NaveEnemigaCazaActual);
        }

        // Resetear ubicación para Naves Enemigas de tipo Transporte
        FVector ubicacionActual = FVector(ubicacionInicialNaves.X - 300.0f, ubicacionInicialNaves.Y, ubicacionInicialNaves.Z);

        // Spawn de Naves Enemigas de tipo Transporte
        for (int j = 0; j < 6; j++) {
            // Calcula la ubicación actual para esta nave
            ubicacionActual.Y = ubicacionInicialNaves.Y + 300.0f * (float)j;
            // Spawnea la nave enemiga de tipo Transporte en la ubicación calculada
            ANaveEnemigaTransporte* NaveEnemigaTransporteActual = World->SpawnActor<ANaveEnemigaTransporte>(ubicacionActual, rotacionNave);
            // Agrega la nave enemiga a un contenedor
            TANavesEnemigasTransporte.Add(NaveEnemigaTransporteActual);
        }

        // Spawn de Naves Enemigas de tipo Espia
        ubicacionActual.X = ubicacionInicialNaves.X - 600.0f;
        for (int j = 0; j < 6; j++) {
            // Calcula la ubicación actual para esta nave
            ubicacionActual.Y = ubicacionInicialNaves.Y + 300.0f * j;
            // Spawnea la nave enemiga de tipo Espia en la ubicación calculada
            ANaveEnemigaEspia* NaveEnemigaEspiaActual = World->SpawnActor<ANaveEnemigaEspia>(ubicacionActual, rotacionNave);
            // Agrega la nave enemiga a un contenedor
            TANavesEnemigasEspia.Add(NaveEnemigaEspiaActual);
        }

        // Spawn de Naves Enemigas de tipo Hacker
        ubicacionActual.X = ubicacionInicialNaves.X - 900.0f;
        for (int j = 0; j < 6; j++) {
            // Calcula la ubicación actual para esta nave
            ubicacionActual.Y = ubicacionInicialNaves.Y + 300.0f * j;
            // Spawnea la nave enemiga de tipo Hacker en la ubicación calculada
            ANaveEnemigaHacker* NaveEnemigaHackerActual = World->SpawnActor<ANaveEnemigaHacker>(ubicacionActual, rotacionNave);
            // Agrega la nave enemiga a un contenedor
            TANavesEnemigasHacker.Add(NaveEnemigaHackerActual);
        }

        // Spawn de Naves Enemigas de tipo Ralentizadora
        ubicacionActual.X = ubicacionInicialNaves.X - 1200.0f;
        for (int j = 0; j < 6; j++) {
            // Calcula la ubicación actual para esta nave
            ubicacionActual.Y = ubicacionInicialNaves.Y + 300.0f * j;
            // Spawnea la nave enemiga de tipo Ralentizadora en la ubicación calculada
            ANaveEnemigaRalentizadora* NaveEnemigaRalentizadoraActual = World->SpawnActor<ANaveEnemigaRalentizadora>(ubicacionActual, rotacionNave);
            // Agrega la nave enemiga a un contenedor
            TANavesEnemigasRalentizadora.Add(NaveEnemigaRalentizadoraActual);
        }
        // Spawn de Naves Enemigas de tipo UwU
        ubicacionActual.X = ubicacionInicialNaves.X - 1500.0f;
        for (int j = 0; j < 6; j++) {
			// Calcula la ubicación actual para esta nave
			ubicacionActual.Y = ubicacionInicialNaves.Y + 300.0f * j;
			// Spawnea la nave enemiga de tipo UwU en la ubicación calculada
			ANaveEnemigaUwU* NaveEnemigaUwUActual = World->SpawnActor<ANaveEnemigaUwU>(ubicacionActual, rotacionNave);
			// Agrega la nave enemiga a un contenedor
			TANavesEnemigasUwU.Add(NaveEnemigaUwUActual);
		}
        // Spawn de Naves Enemigas de tipo Titan
        ubicacionActual.X = ubicacionInicialNaves.X + 650.0f;
        for (int j = 0; j < 1; j++) {
			// Calcula la ubicación actual para esta nave
			ubicacionActual.Y = ubicacionInicialNaves.Y;
			// Spawnea la nave enemiga de tipo Titan en la ubicación calculada
			ANaveEnemigaTitan* NaveEnemigaTitanActual = World->SpawnActor<ANaveEnemigaTitan>(ubicacionActual, rotacionNave);
			// Agrega la nave enemiga a un contenedor
			TANavesEnemigasTitan.Add(NaveEnemigaTitanActual);
		}
    }

}



