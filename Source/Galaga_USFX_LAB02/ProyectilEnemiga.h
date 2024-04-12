#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProyectilEnemiga.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API AProyectilEnemiga : public AActor
{
	GENERATED_BODY()






	
public:	
	AProyectilEnemiga();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
