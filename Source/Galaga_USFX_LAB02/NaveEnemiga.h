#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AComponenteMovimiento.h"
#include "ProyectilEnemiga.h" //xd
#include "NaveEnemiga.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API ANaveEnemiga : public AActor
{
	GENERATED_BODY()









public:
	// Agregar una referencia al proyectil que la nave enemiga va a disparar
	UPROPERTY(EditAnywhere, Category = "Proyectil")
	TSubclassOf<class AGalaga_USFX_LAB02Projectile> ProyectilClass;



public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* mallaNaveEnemiga;

protected:
	float velocidad;
	float velocidadDisparo;
	float resistencia;
	float danoProducido;
	float valorDestruccion;
	float experiencia;
	float energia;
	FString nombre;
	FVector posicion;
	float tiempoDisparo;
	float vida;

	// Posici�n inicial de la nave enemiga
	FVector PosicionInicial;

	// Componente de movimiento de las naves
	UAComponenteMovimiento* MovimientoNavesComponent;

public:
	// Metodos accesores
	FORCEINLINE float GetVelocidad() const { return velocidad; }
	FORCEINLINE float GetVelocidadDisparo() const { return velocidadDisparo; }
	FORCEINLINE float GetResistencia() const { return resistencia; }
	FORCEINLINE float GetDanoProducido() const { return danoProducido; }
	FORCEINLINE float GetValorDestruccion() const { return valorDestruccion; }
	FORCEINLINE float GetTiempoDisparo() const { return tiempoDisparo; }
	FORCEINLINE float GetExperiencia() const { return experiencia; }
	FORCEINLINE float GetEnergia() const { return energia; }
	FORCEINLINE FString GetNombre() const { return nombre; }
	FORCEINLINE FVector GetPosicion() const { return posicion; }

	FORCEINLINE void SetVelocidad(float _velocidad) { velocidad = _velocidad; }
	FORCEINLINE void SetVelocidadDisparo(float _velocidadDisparo) { velocidadDisparo = _velocidadDisparo; }
	FORCEINLINE void SetResistencia(float _resistencia) { resistencia = _resistencia; }
	FORCEINLINE void SetValorDestruccion(float _valorDestruccion) { valorDestruccion = _valorDestruccion; }
	FORCEINLINE void SetDanoProducido(float _danoProducido) { danoProducido = _danoProducido; }
	FORCEINLINE void SetTiempoDisparo(float _tiempoDisparo) { tiempoDisparo = _tiempoDisparo; }
	FORCEINLINE void SetExperiencia(float _experiencia) { experiencia = _experiencia; }
	FORCEINLINE void SetEnergia(float _energia) { energia = _energia; }
	FORCEINLINE void SetNombre(FString _nombre) { nombre = _nombre; }
	FORCEINLINE void SetPosicion(FVector _posicion) { posicion = _posicion; }




public:

	// Sets default values for this actor's properties
	ANaveEnemiga();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:

	virtual void Tick(float DeltaTime) override;

protected:
	void Mover(float DeltaTime) PURE_VIRTUAL(ANaveEnemiga::Mover, );

protected:
	float Radio = 500.0f; // Radio de la circunferencia
	float Angulo = 0.0f; // �ngulo inicial
	float Speed = 20.0f; // Velocidad de rotaci�n
};
