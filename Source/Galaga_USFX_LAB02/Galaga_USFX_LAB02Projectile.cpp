// Derechos de autor de Epic Games, Inc. Todos los derechos reservados

#include "Galaga_USFX_LAB02Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/StaticMesh.h"
#include "NaveEnemiga.h"


AGalaga_USFX_LAB02Projectile::AGalaga_USFX_LAB02Projectile()
{
	// Referencia est�tica al mesh a utilizar para el proyectil
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile"));

	// Crear el componente de mesh para el proyectil
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh0"));
	ProjectileMesh->SetStaticMesh(ProjectileMeshAsset.Object);
	ProjectileMesh->SetupAttachment(RootComponent);
	ProjectileMesh->BodyInstance.SetCollisionProfileName("Projectile");
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AGalaga_USFX_LAB02Projectile::OnHit);		// configurar una notificaci�n para cuando este componente golpee algo
	RootComponent = ProjectileMesh;

	// Usar un ProjectileMovementComponent para gobernar el movimiento del proyectil
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement0"));
	ProjectileMovement->UpdatedComponent = ProjectileMesh;
	ProjectileMovement->InitialSpeed = 9000.f;
	ProjectileMovement->MaxSpeed = 9000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.f; // Sin gravedad

	// Morir despu�s de 3 segundos por defecto
	InitialLifeSpan = 3.0f;
}

void AGalaga_USFX_LAB02Projectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Verificar si OtherActor es una nave enemiga y destruir la nave enemiga
	ANaveEnemiga* NaveEnemiga = Cast<ANaveEnemiga>(OtherActor);
	if (NaveEnemiga)
	{
		// Realizar cualquier acci�n adicional (por ejemplo, puntuaci�n, efectos especiales) aqu� si es necesario

		//...




		// Llamar a la funci�n destruir de la nave enemiga
		NaveEnemiga->Destroy();
	}

	Destroy(); 

	// Solo a�adir impulso y destruir el proyectil si golpea algo f�sico
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 20.0f, GetActorLocation());
	}

	Destroy();
}
