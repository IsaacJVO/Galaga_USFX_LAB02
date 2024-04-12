
#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaTransporte.generated.h"


UCLASS()
class GALAGA_USFX_LAB02_API ANaveEnemigaTransporte : public ANaveEnemiga
{
	GENERATED_BODY()

private:
	int capacidadCarga;
	int estadoCarga;
protected:
	int tiempoDescarga;
	int tipoDescarga;
	float vida;
	float puntaje;
public: //Accesory Methods
	FORCEINLINE int GetCapacidadCarga() const { return capacidadCarga; }
	FORCEINLINE int GetEstadoCarga() const { return estadoCarga; }
	FORCEINLINE int GetTiempoDescarga() const { return tiempoDescarga; }
	FORCEINLINE int GetTipoDescarga() const { return tipoDescarga; }
	FORCEINLINE float GetVida() const { return vida; }
	FORCEINLINE float GetPuntaje() const { return puntaje; }

	FORCEINLINE void SetCapacidadCarga(int _capacidadCarga) { capacidadCarga = _capacidadCarga; }
	FORCEINLINE void SetEstadoCarga(int _estadoCarga) { estadoCarga = _estadoCarga; }
	FORCEINLINE void SetTiempoDescarga(int _tiempoDescarga) { tiempoDescarga = _tiempoDescarga; }
	FORCEINLINE void SetTipoDescarga(int _tipoDescarga) { tipoDescarga = _tipoDescarga; }
	FORCEINLINE void SetVida(float _vida) { vida = _vida; }
	FORCEINLINE void SetPuntaje(float _puntaje) { puntaje = _puntaje; }

public:
	ANaveEnemigaTransporte();

public:
	virtual void Tick(float DeltaTime) override;

public:
	virtual void Mover(float DeltaTime);


};
