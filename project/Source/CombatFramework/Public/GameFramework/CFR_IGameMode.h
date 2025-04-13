#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameMode.h"

#include "CFR_IGameMode.generated.h"

class UUserWidget;

UCLASS(Abstract)
class COMBATFRAMEWORK_API ACFR_IGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	// AGameMode
	void StartPlay() override;

	virtual void PauseGame();
	virtual bool GetCanPlayerSpawn() const { return true; }

	virtual void PlayerWins();
	virtual void PlayerLoses();

protected:
	UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
	TSubclassOf<UUserWidget> InGamePauseMenuWidget = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
	TSubclassOf<UUserWidget> PlayerWinsWidget = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
	TSubclassOf<UUserWidget> PlayerLosesWidget = nullptr;

private:
	void ShowPlayerConditionWidget(TSubclassOf<UUserWidget> InWidget);
};
