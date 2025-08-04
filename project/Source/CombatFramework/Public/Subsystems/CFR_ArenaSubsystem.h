#pragma once

#include "Data/CFR_WaveData.h"

#include "CFR_ArenaSubsystem.generated.h"

class ACFR_AICharacter;

DECLARE_DELEGATE(FOnWaveStarted);
DECLARE_DELEGATE(FOnWaveFinished);
DECLARE_DELEGATE(FOnArenaFinished);

UCLASS()
class UCFR_ArenaSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	void Init(UCFR_WaveDataAsset* InWaveDataAsset);
	void StartArena();
	void FinishArena();

	FOnWaveStarted OnWaveStarted;
	FOnWaveFinished OnWaveFinished;
	FOnArenaFinished OnArenaFinished;

private:
	void SpawnWave(); // Spawn current wave
	void SpawnActors(TSubclassOf<AActor> InActorType, const int InNumber);

	void HandleWaveFinished();
	void HandleEnemyDeath(ACFR_AICharacter* InDeathActor);

	TObjectPtr<UCFR_WaveDataAsset> WaveDataAsset{ nullptr };
	int EnemiesAliveCounter{ 0 };
};
