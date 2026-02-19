#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameMode.h"

#include "CFR_IGameMode.generated.h"

class UUserWidget;

class ACFR_AICharacter;

DECLARE_MULTICAST_DELEGATE(FOnPlayerSpawned);
DECLARE_MULTICAST_DELEGATE(FOnGamePaused);
DECLARE_MULTICAST_DELEGATE(FOnGameResumed);
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

	// ACFR_IGameMode
	virtual void PauseGame();
	virtual void ResumeGame();

	virtual bool GetCanPlayerSpawn() const;

	virtual void PlayerWins();
	virtual void PlayerLoses();

	FOnPlayerSpawned OnPlayerSpawned;
	FOnGamePaused OnGamePaused;
	FOnGameResumed OnGameResumed;
	FOnPlayerWins OnPlayerWins;
	FOnPlayerLoses OnPlayerLoses;

protected:
	void HandlePlayerSpawn();

	UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
	TSubclassOf<UUserWidget> PlayerWinsWidgetType = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
	TSubclassOf<UUserWidget> PlayerLosesWidgetType = nullptr;

	bool bCanPlayerSpawn = false;
};
