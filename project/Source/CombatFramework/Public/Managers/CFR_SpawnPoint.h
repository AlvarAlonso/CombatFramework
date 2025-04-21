#pragma once

#include "CFR_SpawnPoint.generated.h"

class ACFR_CharacterBase;

UCLASS()
class ACFR_SpawnPoint : public AActor
{
	GENERATED_BODY()

public:
	void Spawn(ACFR_CharacterBase* InActor);

private:
	bool CanSpawn();

	UPROPERTY(EditAnywhere)
	float Radius{ 100.0f };
};
