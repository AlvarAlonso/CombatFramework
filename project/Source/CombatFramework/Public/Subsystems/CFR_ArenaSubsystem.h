#pragma once

#include "Data/CFR_WaveData.h"

#include "CFR_ArenaSubsystem.generated.h"

DECLARE_DELEGATE(FOnWaveStarted);
DECLARE_DELEGATE(FOnWaveFinished);

UCLASS()
class UCFR_ArenaSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
	public:
	void Init(UCFR_WaveDataAsset* InWaveDataAsset);
	void Activate();
	
	FOnWaveStarted OnWaveStarted;
	FOnWaveFinished OnWaveFinished;
	
	private:
	void SpawnWave(); // Spawn current wave
	
	TObjectPtr<UCFR_WaveDataAsset> WaveDataAsset{ nullptr };
	int EnemiesAliveCounter{ 0 };
};
