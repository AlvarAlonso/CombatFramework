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
	AActor* SpawnActor(TSubclassOf<AActor> InActorTypeToSpawn, int SpawnPointIndex = -1);
	
	UFUNCTION(BlueprintCallable)
	TArray<AActor*> SpawnActors(TSubclassOf<AActor> InActorTypeToSpawn, const int InNumberActorsToSpawn);

	template<typename T = AActor>
	T* SpawnActor(int SpawnPointIndex = -1)
	{
		return Cast<T>(SpawnActor(T::StaticClass(), SpawnPointIndex));
	}

private:
	void ScanForSpawnPoints();

	TArray<TSoftObjectPtr<ACFR_SpawnPoint>> SpawnPoints;
};
