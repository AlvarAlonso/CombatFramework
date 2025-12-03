#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameMode.h"

#include "CFR_IGameMode.generated.h"

class UUserWidget;

class ACFR_AICharacter;
class UCFR_WaveDataAsset;

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
	virtual bool GetCanPlayerSpawn() const { return true; }

	virtual void PlayerWins();
	virtual void PlayerLoses();

protected:
	UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
	TSubclassOf<UUserWidget> InGamePauseMenuWidgetType = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
	TSubclassOf<UUserWidget> PlayerWinsWidgetType = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
	TSubclassOf<UUserWidget> PlayerLosesWidgetType = nullptr;

private:
	void ShowPlayerConditionWidget(TSubclassOf<UUserWidget> InWidget);
};
