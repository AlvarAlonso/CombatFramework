#pragma once

#include "CFR_SpawnerSubsystem.generated.h"

class ACFR_AICharacter;
class ACFR_SpawnPoint;

DECLARE_MULTICAST_DELEGATE_OneParam(FOnEnemySpawned, ACFR_AICharacter*);
DECLARE_MULTICAST_DELEGATE(FOnEnemyKilled);

UCLASS()
class UCFR_SpawnerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	// UWorldSubsystem
	void PostInitialize() override;

	UFUNCTION(BlueprintCallable)
	AActor* SpawnActor(TSubclassOf<AActor> InActorTypeToSpawn, int SpawnPointIndex = -1);

	UFUNCTION(BlueprintCallable)
	TArray<AActor*> SpawnActors(TSubclassOf<AActor> InActorTypeToSpawn, const int InNumberActorsToSpawn);

	template<typename T = AActor>
	T* SpawnActor(int SpawnPointIndex = -1)
	{
		return Cast<T>(SpawnActor(T::StaticClass(), SpawnPointIndex));
	}

	FOnEnemySpawned OnEnemySpawned;
	FOnEnemyKilled OnEnemyKilled;

private:
	AActor* SpawnAtPoint(ACFR_SpawnPoint* InSpawnPoint, TSubclassOf<AActor> InActorToSpawn);
	void ScanForSpawnPoints();

	TArray<TSoftObjectPtr<ACFR_SpawnPoint>> SpawnPoints;
};
