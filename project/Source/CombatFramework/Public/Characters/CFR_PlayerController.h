#pragma once

#include "CoreMinimal.h"

#include "GameFramework/PlayerController.h"

#include "CFR_PlayerController.generated.h"

UCLASS()
class COMBATFRAMEWORK_API ACFR_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ACFR_PlayerController();

	bool CanRestartPlayer() override;

	/** Called for pause input */
	void HandlePauseGameInput();
};
