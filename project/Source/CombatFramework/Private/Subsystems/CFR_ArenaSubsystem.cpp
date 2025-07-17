#include "Subsystems/CFR_ArenaSubsystem.h"

#include "Subsystems/CFR_SpawnerSubsystem.h"

void UCFR_ArenaSubsystem::Init(UCFR_WaveDataAsset* InWaveDataAsset)
{
	if (!InWaveDataAsset)
	{
		return;
	}

	WaveDataAsset = MoveTemp(InWaveDataAsset);

	for (const auto& enemyData : WaveDataAsset->Enemies)
	{
		EnemiesAliveCounter += enemyData.Value;
	}

	Activate();
}

void UCFR_ArenaSubsystem::Activate()
{
	SpawnWave();
}

void UCFR_ArenaSubsystem::SpawnWave()
{
	if (!WaveDataAsset)
	{
		return;
	}

	const auto& spawnerSubsystem = GetWorld()->GetSubsystem<UCFR_SpawnerSubsystem>();

	if (!spawnerSubsystem)
	{
		UE_LOG(LogTemp, Error, TEXT("No available spawner subsystem for the wave."));
		return;
	}

	for (const auto& enemies : WaveDataAsset->Enemies)
	{
		spawnerSubsystem->SpawnActors(enemies.Key, enemies.Value);
	}
}
