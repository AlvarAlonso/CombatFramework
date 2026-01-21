#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameMode.h"

#include "CFR_IGameMode.generated.h"

class UCommonActivatableWidget;
class UUserWidget;

class ACFR_AICharacter;
class ACFR_CinematicTrigger;
class UCFR_WaveDataAsset;

DECLARE_MULTICAST_DELEGATE(FOnPlayerSpawned);
DECLARE_MULTICAST_DELEGATE(FOnGamePaused);
DECLARE_MULTICAST_DELEGATE(FOnGameResumed);
DECLARE_MULTICAST_DELEGATE(FOnCinematicStarted);
DECLARE_MULTICAST_DELEGATE(FOnCinematicEnded);
DECLARE_MULTICAST_DELEGATE(FOnSkipCutscene);
DECLARE_MULTICAST_DELEGATE(FOnPlayerWins);
DECLARE_MULTICAST_DELEGATE(FOnPlayerLoses);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnEnemySpawned, ACFR_AICharacter*);
DECLARE_MULTICAST_DELEGATE(FOnEnemyKilled);

UCLASS(Abstract)
class COMBATFRAMEWORK_API ACFR_IGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ACFR_IGameMode();

	// AGameMode
	void StartPlay() override;

	// ACFR_IGameMode
	virtual void PauseGame();
	virtual void ResumeGame();

	virtual bool GetCanPlayerSpawn() const;

	virtual void PlayerWins();
	virtual void PlayerLoses();

	virtual void StartCutscene();
	virtual void EndCutscene();
	virtual bool IsCutscenePlaying() const;
	virtual void SkipCutscene();

	virtual void NotifyEnemySpawned(ACFR_AICharacter* InEnemyCharacter);
	virtual void NotifyEnemyKilled();

	FOnPlayerSpawned OnPlayerSpawned;
	FOnGamePaused OnGamePaused;
	FOnGameResumed OnGameResumed;
	FOnCinematicStarted OnCinematicStarted;
	FOnCinematicEnded OnCinematicEnded;
	FOnSkipCutscene OnSkipCutscene;
	FOnPlayerWins OnPlayerWins;
	FOnPlayerLoses OnPlayerLoses;
	FOnEnemySpawned OnEnemySpawned;
	FOnEnemyKilled OnEnemyKilled;

protected:
	UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
	TSubclassOf<UUserWidget> PlayerWinsWidgetType = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
	TSubclassOf<UUserWidget> PlayerLosesWidgetType = nullptr;

private:
	void HandlePlayerSpawn();
	ACFR_CinematicTrigger* CheckIfInitialCutsceneExists();

	bool bCanPlayerSpawn = false;
	bool bIsCutscenePlaying = false;
};
