#pragma once

#include "CFR_SpawnPoint.generated.h"

class UCapsuleComponent;
class USphereComponent;

UCLASS()
class ACFR_SpawnPoint : public AActor
{
	GENERATED_BODY()

public:
	ACFR_SpawnPoint();

	bool FindSpawnPoint(UCapsuleComponent* InCapsuleComponent, FVector& OutLocation);

private:
	bool IsLocationValid(const FVector& InLocation, const FCollisionShape& InCollisionShape) const;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USphereComponent> SphereComponent;

	UPROPERTY(EditDefaultsOnly)
	int MaxAttempts = 10;
};
