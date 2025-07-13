#include "Subsystems/CFR_ArenaSubsystem.h"

#include "Subsystems/CFR_SpawnerSubsystem.h"

void UCFR_Wave::Init(UCFR_WaveDataAsset* InWaveDataAsset)
{
	WaveDataAsset = MoveTemp(InWaveDataAsset);

	for (const auto& enemyData : WaveDataAsset->Enemies)
	{
		EnemiesAliveCounter += enemyData.Value;
	}
}

void UCFR_Wave::Spawn(UWorld* InWorld)
{
	check(InWorld);

	const auto spawnerSubsystem = InWorld->GetSubsystem<UCFR_SpawnerSubsystem>();

	if (!spawnerSubsystem)
	{
		UE_LOG(LogTemp, Error, TEXT("No available spawner subsystem for the wave."));
		return;
	}

	for (auto& enemies : WaveDataAsset->Enemies)
	{
		spawnerSubsystem->SpawnActors(enemies.Key, enemies.Value);
	}
}

void UCFR_ArenaSubsystem::Init(UCFR_WaveDataAsset* InWaveDataAsset)
{
	if (!InWaveDataAsset)
	{
		return;
	}

	Wave = MakeUnique<UCFR_Wave>();
	Wave->Init(MoveTemp(InWaveDataAsset));

	Activate();
}

void UCFR_ArenaSubsystem::Activate()
{
	SpawnWave();
}

void UCFR_ArenaSubsystem::SpawnWave()
{
	if (!Wave)
	{
		return;
	}

	Wave->Spawn(GetWorld());
}
