#pragma once

#include "Data/CFR_WaveData.h"

#include "CFR_ArenaSubsystem.generated.h"

class ACFR_CharacterBase;

DECLARE_DELEGATE(FOnWaveStarted);
DECLARE_DELEGATE(FOnWaveFinished);

UCLASS()
class UCFR_ArenaSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	void Init(UCFR_WaveDataAsset* InWaveDataAsset);
	void StartArena();

	FOnWaveStarted OnWaveStarted;
	FOnWaveFinished OnWaveFinished;

private:
	void SpawnWave(); // Spawn current wave
	void SpawnActors(TSubclassOf<AActor> InActorType, const int InNumber);

	void HandleWaveFinished();
	void HandleEnemyDeath(ACFR_CharacterBase* InDeathActor);

	TObjectPtr<UCFR_WaveDataAsset> WaveDataAsset{ nullptr };
	int EnemiesAliveCounter{ 0 };
};
