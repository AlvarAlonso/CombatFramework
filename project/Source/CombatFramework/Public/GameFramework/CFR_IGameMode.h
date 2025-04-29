#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameMode.h"
#include "Managers/CFR_ActorPoolManager.h"
#include "Managers/CFR_SpawnerManager.h"

#include "CFR_IGameMode.generated.h"

class UUserWidget;

UCLASS(Abstract)
class COMBATFRAMEWORK_API ACFR_IGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	// AGameMode
	void StartPlay() override;

	// ACFR_IGameMode
	virtual void PauseGame();
	virtual bool GetCanPlayerSpawn() const { return true; }

	virtual void PlayerWins();
	virtual void PlayerLoses();

	const UCFR_ActorPoolManager& GetPoolManager();

protected:
	UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
	TSubclassOf<UUserWidget> InGamePauseMenuWidget = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
	TSubclassOf<UUserWidget> PlayerWinsWidget = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
	TSubclassOf<UUserWidget> PlayerLosesWidget = nullptr;

	UCFR_ActorPoolManager* ActorPoolManager{ nullptr };
	UCFR_SpawnerManager* SpawnerManager{ nullptr };

private:
	void ShowPlayerConditionWidget(TSubclassOf<UUserWidget> InWidget);
};
