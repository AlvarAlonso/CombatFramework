#pragma once

#include "Actors/Projectiles/CFR_Projectile.h"

#include "CFR_HitboxProjectile.generated.h"

class UProjectileMovementComponent;

class UCFR_HitboxComponent;

UCLASS(Abstract)
class COMBATFRAMEWORK_API ACFR_HitboxProjectile : public ACFR_Projectile
{
	GENERATED_BODY()

public:
	ACFR_HitboxProjectile();

	void BeginPlay() override;
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hitbox")
	TObjectPtr<UCFR_HitboxComponent> HitboxComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Hitbox")
	TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent;

protected:
	UFUNCTION()
	virtual void OnHitboxOverlap(AActor* OverlappedActor);
};
