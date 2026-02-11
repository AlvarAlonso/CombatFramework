#pragma once

#include "Containers/Queue.h"

#include "Data/CFR_WaveData.h"

#include "CFR_ArenaSubsystem.generated.h"

class ACFR_AICharacter;
class UCFR_IStartEndWaveWidget;

DECLARE_DELEGATE(FOnWaveStarted);
DECLARE_DELEGATE(FOnWaveFinished);
DECLARE_DELEGATE(FOnArenaFinished);

UCLASS(Blueprintable)
class UCFR_ArenaSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// USubsystem interface
	virtual bool ShouldCreateSubsystem(UObject* Outer) const;

	// UCFR_ArenaSubsystem interface
	void StartArena();

	int GetCurrentLevelIndex() const;
	int GetCurrentWaveIndex() const;
	int GetScore() const;

	FOnWaveStarted OnWaveStarted;
	FOnWaveFinished OnWaveFinished;
	FOnArenaFinished OnArenaFinished;

private:
	void StartNextWave();
	void TriggerWaveCutscene();
	void SpawnWave();
	void SpawnActors(TSubclassOf<AActor> InActorType, int InNumber);
	void HandleWaveFinished();
	void HandleOnEnemySpawned(ACFR_AICharacter* InEnemyCharacter);
	void HandleOnEnemyKilled();

	UPROPERTY(EditDefaultsOnly, Category = "Arena")
	TArray<TObjectPtr<UCFR_ArenaDataAsset>> WaveDataAssets;
	UPROPERTY(EditDefaultsOnly, Category = "Arena")
	TObjectPtr<UCFR_IStartEndWaveWidget> StartWaveWidget{ nullptr };
	UPROPERTY(EditDefaultsOnly, Category = "Arena")
	TObjectPtr<UCFR_IStartEndWaveWidget> EndWaveWidget{ nullptr };

	TObjectPtr<UCFR_ArenaDataAsset> CurrentWaveDataAsset{ nullptr };

	TQueue<TObjectPtr<UCFR_ArenaDataAsset>> WaveDataAssetsQueue;

	int CurrentLevelIndex{ 0 };
	int CurrentWaveIndex{ 0 };
	int EnemiesAliveCounter{ 0 };
	int Score{ 0 };
};
