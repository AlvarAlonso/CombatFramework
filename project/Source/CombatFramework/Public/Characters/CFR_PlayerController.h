#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "CFR_PlayerController.generated.h"

class UInputAction;

class UCFR_InGameWidgetManager;
class UCFR_IHUDWidget;

DECLARE_MULTICAST_DELEGATE(FOnAnyInputAction);

UCLASS()
class COMBATFRAMEWORK_API ACFR_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ACFR_PlayerController();

	void BeginPlay() override;
	bool CanRestartPlayer() override;

	// APlayerController
	void SetupInputComponent() override;

	TObjectPtr<UCFR_InGameWidgetManager> HUDWidgetManager;

	FOnAnyInputAction OnAnyInputAction;

private:
	void HandlePauseGameInput();
	void HandleSkipCutsceneInput();
	void HandleAnyInput();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* MappingContext;

	/** Input Actions */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* PauseGameAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* SkipCutsceneAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* AnyInputAction;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UCFR_InGameWidgetManager> HUDWidgetType;
};
