#pragma once

#include "CFR_SpawnerSubsystem.generated.h"

class ACFR_SpawnPoint;
class ACFR_AICharacter;

UCLASS()
class UCFR_SpawnerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	// UWorldSubsystem
	void PostInitialize() override;

	UFUNCTION(BlueprintCallable)
	void SpawnActors(TSubclassOf<ACFR_AICharacter> InActorTypeToSpawn, const int InNumberActorsToSpawn);

private:

	void ScanForSpawnPoints();

	TArray<TSoftObjectPtr<ACFR_SpawnPoint>> SpawnPoints;
};
