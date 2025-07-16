#pragma once

#include "CFR_SpawnPoint.generated.h"

class USphereComponent;

UCLASS()
class ACFR_SpawnPoint : public AActor
{
	GENERATED_BODY()

public:
	ACFR_SpawnPoint();

	void Spawn(AActor* InActor);

private:
	bool CanSpawn();

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USphereComponent> SphereComponent;
};
