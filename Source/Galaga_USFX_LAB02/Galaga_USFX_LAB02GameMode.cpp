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
#include "NaveEnemigaFactory.h"


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
    FVector ubicacionInicialNaves = FVector(1000.0f, -1300.0f, 200.0f);
    FRotator rotacionNave = FRotator(0.0f, 180.0f, 0.0f);

    // Obtiene el mundo del juego
    UWorld* const World = GetWorld();
    if (World != nullptr)
    {
        for (int i = 0; i < 6; i++) {
            FVector ubicacionActual = FVector(ubicacionInicialNaves.X, ubicacionInicialNaves.Y + 300.0f * (float)i, ubicacionInicialNaves.Z);

            ANaveEnemiga* NaveEnemigaCazaActual = ANaveEnemigaFactory::FabricaNaves("Caza", World, ubicacionActual, rotacionNave);

            TANavesEnemigas.Add(NaveEnemigaCazaActual);

        }

        // Resetear ubicación para Naves Enemigas de tipo Transporte
        FVector ubicacionActual = FVector(ubicacionInicialNaves.X - 300.0f, ubicacionInicialNaves.Y, ubicacionInicialNaves.Z);

        // Spawn de Naves Enemigas de tipo Transporte
        for (int j = 0; j < 6; j++) {
            ubicacionActual.Y = ubicacionInicialNaves.Y + 300.0f * (float)j;
            ANaveEnemiga* NaveEnemigaTransporteActual = ANaveEnemigaFactory::FabricaNaves("Transporte", World, ubicacionActual, rotacionNave);
            TANavesEnemigas.Add(NaveEnemigaTransporteActual);  
        }

        ubicacionActual.X = ubicacionInicialNaves.X - 600.0f;
        for (int j = 0; j < 6; j++) {
            ubicacionActual.Y = ubicacionInicialNaves.Y + 300.0f * j;
            ANaveEnemiga* NaveEnemigaEspiaActual = ANaveEnemigaFactory::FabricaNaves("Espia", World, ubicacionActual, rotacionNave);
            TANavesEnemigas.Add(NaveEnemigaEspiaActual);
        }

        ubicacionActual.X = ubicacionInicialNaves.X - 900.0f;
        for (int j = 0; j < 6; j++) {
            ubicacionActual.Y = ubicacionInicialNaves.Y + 300.0f * j;
            ANaveEnemiga* NaveEnemigaHackerActual = ANaveEnemigaFactory::FabricaNaves("Hacker", World, ubicacionActual, rotacionNave);
            TANavesEnemigas.Add(NaveEnemigaHackerActual);
        }

        ubicacionActual.X = ubicacionInicialNaves.X - 1200.0f;
        for (int j = 0; j < 6; j++) {
            ubicacionActual.Y = ubicacionInicialNaves.Y + 300.0f * j;
            ANaveEnemiga* NaveEnemigaRalentizadoraActual = ANaveEnemigaFactory::FabricaNaves("Ralentizadora", World, ubicacionActual, rotacionNave);
            TANavesEnemigas.Add(NaveEnemigaRalentizadoraActual); 
        }

        ubicacionActual.X = ubicacionInicialNaves.X - 1500.0f;
        for (int j = 0; j < 6; j++) {
			ubicacionActual.Y = ubicacionInicialNaves.Y + 300.0f * j;
            ANaveEnemiga* NaveEnemigaUwUActual = ANaveEnemigaFactory::FabricaNaves("UwU", World, ubicacionActual, rotacionNave);
			TANavesEnemigas.Add(NaveEnemigaUwUActual);
		}

    }

}



