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
class ANaveEnemigaUwU;
class ANaveEnemigaRalentizadora;
class ANaveEnemigaTitan;



UCLASS(MinimalAPI)
class AGalaga_USFX_LAB02GameMode : public AGameModeBase
{
	GENERATED_BODY()





public:
	AGalaga_USFX_LAB02GameMode();

protected:
	virtual void BeginPlay() override;


public:
	TArray<ANaveEnemiga*> TANavesEnemigas;



};