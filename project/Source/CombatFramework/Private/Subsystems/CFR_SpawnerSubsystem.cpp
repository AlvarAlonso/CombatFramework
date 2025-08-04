#include "Subsystems/CFR_SpawnerSubsystem.h"

#include "Kismet/GameplayStatics.h"

#include "Actors/CFR_SpawnPoint.h"
#include "Subsystems/CFR_ArenaSubsystem.h"
#include "Subsystems/CFR_PoolSubsystem.h"

void UCFR_SpawnerSubsystem::PostInitialize()
{
	ScanForSpawnPoints();

	auto arenaSubsystem = GetWorld()->GetSubsystem<UCFR_ArenaSubsystem>();
	arenaSubsystem->OnWaveFinished.BindUObject(this, &UCFR_SpawnerSubsystem::ScanForSpawnPoints);
}

AActor* UCFR_SpawnerSubsystem::SpawnActor(TSubclassOf<AActor> InActorTypeToSpawn, int SpawnPointIndex)
{
	const auto world = GetWorld();
	check(world);

	if (SpawnPoints.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("SpawnActor for SpawnerSubsystem called without SpawnPoints available."));
		return nullptr;
	}

	auto actor = UCFR_PoolSubsystem::GetActor(world, InActorTypeToSpawn);
	check(actor);
	
	bool bUseRandomSpawnPoint = SpawnPointIndex < 0 || SpawnPointIndex >= SpawnPoints.Num();
	const auto spawnPointIndex = bUseRandomSpawnPoint ? FMath::RandRange(0, SpawnPoints.Num() - 1) : SpawnPointIndex;

	if (SpawnPoints[spawnPointIndex]->SpawnActor(actor))
	{
		return actor;
	}

	return nullptr;
}

TArray<AActor*> UCFR_SpawnerSubsystem::SpawnActors(TSubclassOf<AActor> InActorTypeToSpawn, const int InNumberActorsToSpawn)
{
	const auto world = GetWorld();
	check(world);

	if (SpawnPoints.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("SpawnActors for SpawnerSubsystem called without SpawnPoints available."));
		return {};
	}

	TArray<AActor*> spawnedActors;
	spawnedActors.Reserve(InNumberActorsToSpawn);

	const auto actorsToSpawnPerSpawnPoint = InNumberActorsToSpawn / SpawnPoints.Num();
	int32 spawnPointIndex{ 0 };

	for (const auto& spawnPoint : SpawnPoints)
	{
		const int32 numberActorsToSpawn = spawnPointIndex < (InNumberActorsToSpawn % SpawnPoints.Num()) ? actorsToSpawnPerSpawnPoint + 1 : actorsToSpawnPerSpawnPoint;

		for (int32 index = 0; index < numberActorsToSpawn; ++index)
		{
			auto actor = UCFR_PoolSubsystem::GetActor(world, InActorTypeToSpawn);
			check(actor);

			if (spawnPoint->SpawnActor(actor))
			{
				spawnedActors.Add(actor);
			}
		}

		++spawnPointIndex;
	}

	return spawnedActors;
}

void UCFR_SpawnerSubsystem::ScanForSpawnPoints()
{
	SpawnPoints.Empty();

	const auto world = GetWorld();
	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(world, ACFR_SpawnPoint::StaticClass(), actors);

	SpawnPoints.Reserve(actors.Num());

	for (auto actor : actors)
	{
		SpawnPoints.Add(Cast<ACFR_SpawnPoint>(actor));
	}
}
