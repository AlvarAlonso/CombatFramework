#pragma once

#include "CoreMinimal.h"

#include "CFR_InGameWidgetManager.generated.h"

class ACFR_PlayerController;
class UCFR_IHUDWidget;
class UCFR_IPauseMenuWidget;
class UCFR_ISkipCutsceneWidget;

UCLASS()
class COMBATFRAMEWORK_API UCFR_InGameWidgetManager : public UObject
{
	GENERATED_BODY()

public:
	// UCFR_InGameWidgetManager
	void Initialize(ACFR_PlayerController* OwningPlayerController);
	bool IsHUDWidgetVisible() const;
	bool IsSkipCutsceneWidgetVisible() const;

private:
	TWeakObjectPtr<ACFR_PlayerController> OwningPlayerController;

	TObjectPtr<UCFR_IHUDWidget> HUDWidget;
	TObjectPtr<UCFR_IPauseMenuWidget> PauseMenuWidget;
	TObjectPtr<UCFR_ISkipCutsceneWidget> SkipCutsceneWidget;

	void HandleOnPlayerSpawned();
	void HandleOnGamePaused();
	void HandleOnGameResumed();
	void HandleOnPlayerWins();
	void HandleOnPlayerLoses();
	void HandleOnSkipCutscene();
	void HandleOnAnyInput();
};
