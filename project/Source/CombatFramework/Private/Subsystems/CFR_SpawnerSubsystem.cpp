#include "Subsystems/CFR_SpawnerSubsystem.h"

#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

#include "Actors/CFR_SpawnPoint.h"
#include "Characters/CFR_AICharacter.h"
#include "Subsystems/CFR_PoolSubsystem.h"

void UCFR_SpawnerSubsystem::PostInitialize()
{
	ScanForSpawnPoints();
}

AActor* UCFR_SpawnerSubsystem::SpawnActor(TSubclassOf<AActor> InActorTypeToSpawn, int SpawnPointIndex)
{
	if (SpawnPoints.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("SpawnActor for SpawnerSubsystem called without SpawnPoints available."));
		return nullptr;
	}

	const int32 Index =
		(SpawnPointIndex >= 0 && SpawnPointIndex < SpawnPoints.Num())
		? SpawnPointIndex
		: FMath::RandRange(0, SpawnPoints.Num() - 1);

	return SpawnAtPoint(SpawnPoints[Index].Get(), InActorTypeToSpawn);
}

TArray<AActor*> UCFR_SpawnerSubsystem::SpawnActors(TSubclassOf<AActor> InActorTypeToSpawn, const int InNumberActorsToSpawn)
{
	ScanForSpawnPoints();

	if (SpawnPoints.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("SpawnActors for SpawnerSubsystem called without SpawnPoints available."));
		return {};
	}

	TArray<AActor*> spawnedActors;
	spawnedActors.Reserve(InNumberActorsToSpawn);

	const auto numPoints = SpawnPoints.Num();
	const auto actorsToSpawnPerSpawnPoint = InNumberActorsToSpawn / numPoints;
	const auto moduloActors = InNumberActorsToSpawn % numPoints;
	int32 spawnPointIndex{ 0 };

	for (const auto& spawnPoint : SpawnPoints)
	{
		const int32 numberActorsToSpawn = actorsToSpawnPerSpawnPoint + (spawnPointIndex < moduloActors ? 1 : 0);

		for (int32 index = 0; index < numberActorsToSpawn; ++index)
		{
			if (auto actor = SpawnAtPoint(spawnPoint.Get(), InActorTypeToSpawn))
			{
				spawnedActors.Add(actor);
			}
		}

		++spawnPointIndex;
	}

	return spawnedActors;
}

AActor* UCFR_SpawnerSubsystem::SpawnAtPoint(ACFR_SpawnPoint* InSpawnPoint, TSubclassOf<AActor> InActorToSpawn)
{
	const auto world = GetWorld();
	check(world);

	auto capsuleComponent = InActorToSpawn->GetDefaultObject<AActor>()->FindComponentByClass<UCapsuleComponent>();
	if (!capsuleComponent)
		return nullptr;

	FVector spawnLocation;
	if (!InSpawnPoint->FindSpawnPoint(capsuleComponent, spawnLocation))
	{
		return nullptr;
	}

	auto actor = UCFR_PoolSubsystem::GetActor(world, InActorToSpawn);
	check(actor); // I would expect the pool to always return a valid actor.

	if (!world->FindTeleportSpot(actor, spawnLocation, {}))
	{
		UCFR_PoolSubsystem::ReleaseActor(actor);
		return nullptr;
	}

	actor->SetActorLocation(spawnLocation);

	if (auto character = Cast<ACFR_AICharacter>(actor))
	{
		character->Activate();
		character->OnHandleDeathEvent.AddUObject(this, &UCFR_SpawnerSubsystem::HandleEnemyKilled);

		OnEnemySpawned.Broadcast(character);
	}

	return actor;
}

void UCFR_SpawnerSubsystem::ScanForSpawnPoints()
{
	SpawnPoints.Empty();

	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACFR_SpawnPoint::StaticClass(), actors);

	SpawnPoints.Reserve(actors.Num());

	for (auto actor : actors)
	{
		SpawnPoints.Add(Cast<ACFR_SpawnPoint>(actor));
	}
}

void UCFR_SpawnerSubsystem::HandleEnemyKilled(ACFR_AICharacter* InEnemyKilled)
{
	OnEnemyKilled.Broadcast();
}
