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
	ACFR_IGameMode();

	// AGameMode
	void StartPlay() override;

	// ACFR_IGameMode
	virtual void PauseGame();
	virtual bool GetCanPlayerSpawn() const { return true; }

	virtual void PlayerWins();
	virtual void PlayerLoses();

	const UCFR_ActorPoolManager* GetPoolManager();

protected:
	UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
	TSubclassOf<UUserWidget> InGamePauseMenuWidget = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
	TSubclassOf<UUserWidget> PlayerWinsWidget = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
	TSubclassOf<UUserWidget> PlayerLosesWidget = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Instanced, Category = Manager)
	TObjectPtr<UCFR_ActorPoolManager> ActorPoolManager;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Manager)
	TObjectPtr<UCFR_SpawnerManager> SpawnerManager;

private:
	void ShowPlayerConditionWidget(TSubclassOf<UUserWidget> InWidget);
};
