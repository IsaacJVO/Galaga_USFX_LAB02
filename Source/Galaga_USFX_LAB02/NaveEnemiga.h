#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AComponenteMovimiento.h"
#include "AComponenteInvisible.h"
#include "NaveEnemiga.generated.h"



UCLASS(ABSTRACT)
class GALAGA_USFX_LAB02_API ANaveEnemiga : public AActor
{
	GENERATED_BODY()











public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))

	UStaticMeshComponent* mallaNaveEnemiga;

	// Componente de movimiento de las naves
	UAComponenteMovimiento* MovimientoNavesComponent;


protected:
	float Salud;
	float Dano;
	float Velocidad;
	FString nombre;
	FVector posicion;

protected:
	float Radio = 1000.0f;
	float Angulo = 0.0f;
	float Speed = 2.0f;



public:
	// Metodos accesores
public:
	// Métodos de acceso para salud, daño y velocidad
	FORCEINLINE float ObtenerSalud() const { return Salud; }
	FORCEINLINE void EstablecerSalud(float NuevaSalud) { Salud = NuevaSalud; }

	FORCEINLINE float ObtenerDano() const { return Dano; }
	FORCEINLINE void EstablecerDano(float NuevoDano) { Dano = NuevoDano; }

	FORCEINLINE float ObtenerVelocidad() const { return Velocidad; }
	FORCEINLINE void EstablecerVelocidad(float NuevaVelocidad) { Velocidad = NuevaVelocidad; }

	FORCEINLINE FString GetNombre() const { return nombre; }
	FORCEINLINE FVector GetPosicion() const { return posicion; }

	FORCEINLINE void SetNombre(FString _nombre) { nombre = _nombre; }
	FORCEINLINE void SetPosicion(FVector _posicion) { posicion = _posicion; }




public:


	ANaveEnemiga();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")

	UAComponenteInvisible* AComponenteInvisible;

protected:

	virtual void BeginPlay() override;
	void FireProjectile();
	float FireRate;
	FTimerHandle FireTimerHandle;

protected:

	virtual void Tick(float DeltaTime) override;

protected:
	void Mover(float DeltaTime) PURE_VIRTUAL(ANaveEnemiga::Mover, );

public:

	// Mueve al enemigo hacia una ubicación objetivo
	void MoverHacia(FVector UbicacionObjetivo);

	// Realiza un ataque
	void Atacar();

	// Recibe daño y reduce la salud del enemigo
	void RecibirDanio(float CantidadDanio);

	// Realiza las acciones necesarias cuando el enemigo muere
	void Morir();


};