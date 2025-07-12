#include "Subsystems/CFR_ArenaSubsystem.h"

void UCFR_Wave::Init(UCFR_WaveDataAsset* InWaveDataAsset)
{
	WaveDataAsset = MoveTemp(InWaveDataAsset);

	for (const auto& enemyData : WaveDataAsset->Enemies)
	{
		EnemiesAliveCounter += enemyData.Value;
	}
}

void UCFR_Arena::Init(UCFR_WaveDataAsset* InWaveDataAsset)
{
	if (!InWaveDataAsset)
	{
		return;
	}

	Wave = MakeUnique<UCFR_Wave>();
	Wave->Init(MoveTemp(InWaveDataAsset));
}

void UCFR_Arena::Activate()
{
	SpawnWave();
}

void UCFR_Arena::SpawnWave()
{
	if (!Wave)
	{
		return;
	}
}
