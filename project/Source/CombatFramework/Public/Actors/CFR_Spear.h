#pragma once

#include "Actors/Projectiles/CFR_HitboxProjectile.h"

#include "CFR_Spear.generated.h"

class UStaticMeshComponent;
class UProjectileMovementComponent;

UCLASS(Blueprintable, Abstract)
class COMBATFRAMEWORK_API ACFR_Spear : public ACFR_HitboxProjectile
{
	GENERATED_BODY()

public:
	ACFR_Spear();

	void BeginPlay() override;
	void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void LaunchSpear(const AActor* TargetActor = nullptr);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spear")
	TObjectPtr<UStaticMeshComponent> SpearMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spear")
	int SecondsAlive = 3;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spear")
	float MaxRange = INFINITY;

	UPROPERTY()
	float Angle = 0.0f;

	UPROPERTY()
	float DistanceFromCaster = 100.0f;

private:
	bool bLaunched = false;
};
