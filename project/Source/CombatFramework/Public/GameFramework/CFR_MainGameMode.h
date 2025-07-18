#pragma once

#include "CoreMinimal.h"

#include "GameFramework/CFR_IGameMode.h"

#include "CFR_MainGameMode.generated.h"

class UUserWidget;

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

private:
	bool bCanPlayerSpawn = false;
};
