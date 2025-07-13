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
	TSubclassOf<UUserWidget> InGamePauseMenuWidget = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
	TSubclassOf<UUserWidget> PlayerWinsWidget = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
	TSubclassOf<UUserWidget> PlayerLosesWidget = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = Waves)
	TSubclassOf<UCFR_WaveDataAsset> InitialWave;

	UPROPERTY(EditDefaultsOnly, Category = Pool)
	TMap<TSubclassOf<ACFR_AICharacter>, int32> ActorPools;

private:
	void ShowPlayerConditionWidget(TSubclassOf<UUserWidget> InWidget);
};
