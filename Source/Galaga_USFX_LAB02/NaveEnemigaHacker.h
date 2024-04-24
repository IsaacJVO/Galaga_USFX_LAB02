
#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaHacker.generated.h"


UCLASS()
class GALAGA_USFX_LAB02_API ANaveEnemigaHacker : public ANaveEnemiga
{
	GENERATED_BODY()

	
public:
	ANaveEnemigaHacker();

	FString tipoHacker = "Hacker";
public:
	virtual void Tick(float DeltaTime) override;

public:
	virtual void Mover(float DeltaTime);



};
