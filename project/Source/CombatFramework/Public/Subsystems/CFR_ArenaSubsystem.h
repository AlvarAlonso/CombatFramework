#pragma once

#include "Data/CFR_WaveData.h"

#include "CFR_ArenaSubsystem.generated.h"

class ACFR_AICharacter;
class UCFR_IStartEndWaveWidget;

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

	int GetCurrentWaveIndex() const;
	int GetScore() const;

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
	int CurrentWaveIndex{ 0 };
	int Score{ 0 };

	TObjectPtr<UCFR_IStartEndWaveWidget> StartWaveWidget{ nullptr };
	TObjectPtr<UCFR_IStartEndWaveWidget> EndWaveWidget{ nullptr };
};
