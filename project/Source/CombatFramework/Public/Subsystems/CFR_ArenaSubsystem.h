#pragma once

#include "Data/CFR_WaveData.h"

#include "CFR_ArenaSubsystem.generated.h"

DECLARE_DELEGATE(FOnWaveStarted);
DECLARE_DELEGATE(FOnWaveFinished);

class UCFR_Wave
{
public:
	void Init(UCFR_WaveDataAsset* InWaveDataAsset);

	FOnWaveStarted OnWaveStarted;
	FOnWaveFinished OnWaveFinished;

private:
	TObjectPtr<UCFR_WaveDataAsset> WaveDataAsset{ nullptr };
	int EnemiesAliveCounter{ 0 };
};

UCLASS()
class UCFR_Arena : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	void Init(UCFR_WaveDataAsset* InWaveDataAsset);
	void Activate();

private:
	void SpawnWave(); // Spawn current wave

	TUniquePtr<UCFR_Wave> Wave;
};
