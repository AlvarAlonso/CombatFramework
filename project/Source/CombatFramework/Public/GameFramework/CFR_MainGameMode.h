#pragma once

#include "CoreMinimal.h"

#include "GameFramework/CFR_IGameMode.h"

#include "CFR_MainGameMode.generated.h"

class UUserWidget;
class ULevelSequence;
class ULevelSequencePlayer;

UCLASS()
class COMBATFRAMEWORK_API ACFR_MainGameMode : public ACFR_IGameMode
{
	GENERATED_BODY()

public:
	// AGameMode
	void StartPlay() override;
	void RestartPlayer(AController* InNewPlayerController) override;

	// ACFR_IGameMode
	bool GetCanPlayerSpawn() const override;
	void ShowSkipCutsceneWidget() override;
	void SkipCutscene() override;

	// ACFR_MainGameMode
	UFUNCTION(BlueprintCallable)
	int GetCurrentWaveIndex() const;
	UFUNCTION(BlueprintCallable)
	int GetScore() const;

private:
	UFUNCTION()
	void HandlePlayerSpawn();

	UPROPERTY(EditDefaultsOnly, Category = "MainGameMode")
	ULevelSequence* IntroSequence;

	UPROPERTY()
	UUserWidget* SkipCutsceneWidgetInstance;

	ULevelSequencePlayer* CurrentLevelSequencePlayer;

	bool bCanPlayerSpawn = false;
};
