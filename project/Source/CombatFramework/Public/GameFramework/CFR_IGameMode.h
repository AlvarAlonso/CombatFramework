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

UCLASS(Abstract)
class COMBATFRAMEWORK_API ACFR_IGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ACFR_IGameMode();

	// AGameMode
	void StartPlay() override;
	void HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer) override;

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

	FOnPlayerSpawned OnPlayerSpawned;
	FOnGamePaused OnGamePaused;
	FOnGameResumed OnGameResumed;
	FOnCinematicStarted OnCinematicStarted;
	FOnCinematicEnded OnCinematicEnded;
	FOnSkipCutscene OnSkipCutscene;
	FOnPlayerWins OnPlayerWins;
	FOnPlayerLoses OnPlayerLoses;

protected:
	UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
	TSubclassOf<UUserWidget> PlayerWinsWidgetType = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
	TSubclassOf<UUserWidget> PlayerLosesWidgetType = nullptr;

private:
	void ShowPlayerConditionWidget(TSubclassOf<UUserWidget> InWidget);
	void HandlePlayerSpawn();
	ACFR_CinematicTrigger* CheckIfInitialCutsceneExists();

	bool bCanPlayerSpawn = false;
	bool bIsCutscenePlaying = false;
};
