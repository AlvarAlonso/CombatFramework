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

	// UCFR_WidgetSubsystem
	void ShowWidget(FName InWidgetName);
	void HideWidget(FName InWidgetName);

	bool IsWidgetVisible(FName InWidgetName) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TMap<FName, TSubclassOf<UUserWidget>> WidgetClasses;

private:
	void SetWidgetVisibility(const FName InWidgetName, ESlateVisibility InVisibility);

	UPROPERTY()
	TMap<FName, TObjectPtr<UUserWidget>> Widgets;

	TWeakObjectPtr<ACFR_PlayerController> OwningPlayerController;

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
