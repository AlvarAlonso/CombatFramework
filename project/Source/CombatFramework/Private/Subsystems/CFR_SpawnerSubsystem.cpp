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

void UCFR_SpawnerSubsystem::SpawnActors(TSubclassOf<ACFR_AICharacter> InActorTypeToSpawn, const int InNumberActorsToSpawn)
{
	const auto world = GetWorld();
	check(world);

	if (SpawnPoints.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("SpawnActors for SpawnerSubsystem called without SpawnPoints available."));
		return;
	}

	const auto actorsToSpawnPerSpawnPoint = InNumberActorsToSpawn / SpawnPoints.Num();
	int32 spawnPointIndex{ 0 };
	for (const auto& spawnPoint : SpawnPoints)
	{
		const int32 numberActorsToSpawn = spawnPointIndex < (InNumberActorsToSpawn % SpawnPoints.Num()) ? actorsToSpawnPerSpawnPoint + 1 : actorsToSpawnPerSpawnPoint;

		for (int32 index = 0; index < numberActorsToSpawn; ++index)
		{
			if (auto actor = UCFR_PoolSubsystem::GetActor(world, InActorTypeToSpawn))
			{
				spawnPoint->Spawn(actor);
			}
		}

		++spawnPointIndex;
	}
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
