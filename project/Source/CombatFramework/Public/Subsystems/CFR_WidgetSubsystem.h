#pragma once

#include "CoreMinimal.h"

#include "CFR_WidgetSubsystem.generated.h"

class ACFR_PlayerController;
class UCFR_IHUDWidget;
class UCFR_IPauseMenuWidget;
class UCFR_ISkipCutsceneWidget;

UCLASS(Blueprintable)
class COMBATFRAMEWORK_API UCFR_WidgetSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	// USubsystem interface
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

	// UWorldSubsystem
	void OnWorldBeginPlay(UWorld& InWorld) override;

	bool IsHUDWidgetVisible() const;
	bool IsSkipCutsceneWidgetVisible() const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UUserWidget> HUDWidgetType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UCFR_IPauseMenuWidget> PauseMenuWidgetType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UCFR_ISkipCutsceneWidget> SkipCutsceneWidgetType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UUserWidget> PlayerWinsWidgetType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UUserWidget> PlayerLosesWidgetType;

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

	void HideHUDWidget();
	void ShowHUDWidget();
};
