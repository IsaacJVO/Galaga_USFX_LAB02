
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

	FString tipoRalentizadora = "Ralentizadora";
public:
	virtual void Tick(float DeltaTime) override;
public:
	virtual void Mover(float DeltaTime);



};
