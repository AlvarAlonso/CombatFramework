#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameMode.h"

#include "CFR_IGameMode.generated.h"

class UCommonActivatableWidget;
class UUserWidget;

class ACFR_AICharacter;
class UCFR_WaveDataAsset;

DECLARE_MULTICAST_DELEGATE(FOnPlayerSpawned);
DECLARE_MULTICAST_DELEGATE(FOnGamePaused);
DECLARE_MULTICAST_DELEGATE(FOnGameResumed);
DECLARE_MULTICAST_DELEGATE(FOnSkipCutscene);

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
	virtual void SpawnPlayer();

	virtual void PlayerWins();
	virtual void PlayerLoses();

	virtual bool IsCutscenePlaying() const;
	virtual void SkipCutscene();

	FOnPlayerSpawned OnPlayerSpawned;
	FOnGamePaused OnGamePaused;
	FOnGameResumed OnGameResumed;
	FOnSkipCutscene OnSkipCutscene;

protected:
	UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
	TSubclassOf<UUserWidget> PlayerWinsWidgetType = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
	TSubclassOf<UUserWidget> PlayerLosesWidgetType = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
	TSubclassOf<UUserWidget> SkipCutsceneWidgetType = nullptr;

private:
	void ShowPlayerConditionWidget(TSubclassOf<UUserWidget> InWidget);
};
