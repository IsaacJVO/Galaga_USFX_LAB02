// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Galaga_USFX_LAB02GameMode.generated.h"

class ANaveEnemiga;
class ANaveEnemigaCaza;
class ANaveEnemigaTransporte;
class ANaveEnemigaEspia;
class ANaveEnemigaHacker;


UCLASS(MinimalAPI)
class AGalaga_USFX_LAB02GameMode : public AGameModeBase
{
	GENERATED_BODY()





public:
	AGalaga_USFX_LAB02GameMode();


protected:

	virtual void BeginPlay() override;

public:
	ANaveEnemiga* NaveEnemiga01;
	ANaveEnemigaCaza* NaveEnemigaCaza01;
	ANaveEnemigaCaza* NaveEnemigaCaza02;
	ANaveEnemigaTransporte* NaveEnemigaTransporte01;
	ANaveEnemigaTransporte* NaveEnemigaTransporte02;

public:
	TArray<ANaveEnemiga*> TANavesEnemigas;
	TArray<ANaveEnemigaCaza*> TANavesEnemigasCaza;
	TArray<ANaveEnemigaTransporte*> TANavesEnemigasTransporte;
	TArray<ANaveEnemigaEspia*> TANavesEnemigasEspia;
	TArray<ANaveEnemigaHacker*> TANavesEnemigasHacker;

};