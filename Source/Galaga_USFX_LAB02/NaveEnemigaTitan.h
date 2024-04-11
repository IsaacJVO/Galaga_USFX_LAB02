// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaTitan.generated.h"


UCLASS()
class GALAGA_USFX_LAB02_API ANaveEnemigaTitan : public ANaveEnemiga
{
	GENERATED_BODY()

	float vida;
	float movimientos;
	float hijos;
	float disparosRapidos;
	float danoDeExplosion;

public:
	FORCEINLINE float GetVida() const { return vida; }
	FORCEINLINE float GetMovimientos() const { return movimientos; }
	FORCEINLINE float GetHijos() const { return hijos; }
	FORCEINLINE float GetDisparosRapidos() const { return disparosRapidos; }
	FORCEINLINE float GetDanoDeExplosion() const { return danoDeExplosion; }

	FORCEINLINE void SetVida(float _vida) { vida = _vida; }
	FORCEINLINE void SetMovimientos(float _movimientos) { movimientos = _movimientos; }
	FORCEINLINE void SetHijos(float _hijos) { hijos = _hijos; }
	FORCEINLINE void SetDisparosRapidos(float _disparosRapidos) { disparosRapidos = _disparosRapidos; }
	FORCEINLINE void SetDanoDeExplosion(float _danoDeExplosion) { danoDeExplosion = _danoDeExplosion; }


public:
	ANaveEnemigaTitan();
public:
	virtual void Tick(float DeltaTime) override;
public:
	virtual void Mover(float DeltaTime);

private:
	int DireccionMovimientoVertical;

private:
	float VelocidadMovimiento = 250.0f;

protected:
	float Radio = 500.0f; // Radio de la circunferencia
	float Angulo = 0.0f; // �ngulo inicial
	float Speed = 20.0f; // Velocidad de rotaci�n
};
