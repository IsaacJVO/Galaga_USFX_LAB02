#pragma once

#include "NaveEnemiga.h"
#include "CoreMinimal.h"
#include "NaveEnemigaCaza.generated.h"


UCLASS()

class GALAGA_USFX_LAB02_API ANaveEnemigaCaza : public ANaveEnemiga
{
	GENERATED_BODY()











private:
	float disparosRapidos;
	float velocidadRapida;

protected:
	float suicidio;
	float vida;
	float tiempoVida;
	float tiempoAtaque;

	FORCEINLINE float GetDisparosRapidos() const { return disparosRapidos; }
	FORCEINLINE float GetVelocidadRapida() const { return velocidadRapida; }
	FORCEINLINE float GetSuicidio() const { return suicidio; }
	FORCEINLINE float GetVida() const { return vida; }
	FORCEINLINE float GetTiempoVida() const { return tiempoVida; }
	FORCEINLINE float GetTiempoAtaque() const { return tiempoAtaque; }

	FORCEINLINE void SetDisparosRapidos(float _disparosRapidos) { disparosRapidos = _disparosRapidos; }
	FORCEINLINE void SetVelocidadRapida(float _velocidadRapida) { velocidadRapida = _velocidadRapida; }
	FORCEINLINE void SetSuicidio(float _suicidio) { suicidio = _suicidio; }
	FORCEINLINE void SetVida(float _vida) { vida = _vida; }
	FORCEINLINE void SetTiempoVida(float _tiempoVida) { tiempoVida = _tiempoVida; }
	FORCEINLINE void SetTiempoAtaque(float _tiempoAtaque) { tiempoAtaque = _tiempoAtaque; }



public:
	ANaveEnemigaCaza();

public:
	virtual void Tick(float DeltaTime) override;
	virtual void Mover(float DeltaTime);

};
