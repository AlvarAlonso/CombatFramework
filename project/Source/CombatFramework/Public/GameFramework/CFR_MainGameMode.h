#pragma once

#include "Actors/CFR_CinematicTriggerType.h"
#include "GameFramework/CFR_IGameMode.h"

#include "CFR_MainGameMode.generated.h"

class UCFR_CinematicSubsystem;
class ACFR_CinematicTrigger;

UCLASS()
class COMBATFRAMEWORK_API ACFR_MainGameMode : public ACFR_IGameMode
{
	GENERATED_BODY()

	static ACFR_CinematicTrigger* FindCinematicTrigger(UCFR_CinematicSubsystem* InCinematicSubsystem, ECinematicTriggerType InTriggerType);

public:
	// AGameMode
	void StartPlay() override;
	void RestartPlayer(AController* InNewPlayerController) override;

	// ACFR_IGameMode
	void PlayerWins() override;

	// ACFR_MainGameMode
	UFUNCTION(BlueprintCallable)
	int GetCurrentWaveIndex() const;
	UFUNCTION(BlueprintCallable)
	int GetScore() const;
};
