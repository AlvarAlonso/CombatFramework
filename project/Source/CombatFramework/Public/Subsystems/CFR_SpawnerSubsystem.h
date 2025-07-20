#pragma once

#include "CFR_SpawnerSubsystem.generated.h"

class ACFR_SpawnPoint;

UCLASS()
class UCFR_SpawnerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	// UWorldSubsystem
	void PostInitialize() override;

	UFUNCTION(BlueprintCallable)
	TArray<AActor*> SpawnActors(TSubclassOf<AActor> InActorTypeToSpawn, const int InNumberActorsToSpawn);

private:

	void ScanForSpawnPoints();

	TArray<TSoftObjectPtr<ACFR_SpawnPoint>> SpawnPoints;
};
