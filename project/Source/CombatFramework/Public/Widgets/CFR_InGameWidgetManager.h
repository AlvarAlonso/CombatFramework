#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "CFR_InGameWidgetManager.generated.h"

class UCFR_IHUDWidget;
class UCFR_IPauseMenuWidget;
class UCFR_ISkipCutsceneWidget;

UCLASS()
class COMBATFRAMEWORK_API UCFR_InGameWidgetManager : public UUserWidget
{
	GENERATED_BODY()

public:
	// UUserWidget interface
	bool Initialize() override;

	// UCFR_InGameWidgetManager
	bool IsHUDWidgetVisible() const;
	bool IsSkipCutsceneWidgetVisible() const;

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> HUDWidgetType;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UCFR_IPauseMenuWidget> PauseMenuWidgetType;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UCFR_ISkipCutsceneWidget> SkipCutsceneWidgetType;

private:
	TObjectPtr<UCFR_IHUDWidget> HUDWidget;
	TObjectPtr<UCFR_IPauseMenuWidget> PauseMenuWidget;
	TObjectPtr<UCFR_ISkipCutsceneWidget> SkipCutsceneWidget;

	void HandleOnPlayerSpawned();
	void HandleOnGamePaused();
	void HandleOnGameResumed();
	void HandleOnSkipCutscene();
	void HandleOnShowPlayerConditionWidget();
	void HandleOnShowSkipCutsceneWidget();
};
