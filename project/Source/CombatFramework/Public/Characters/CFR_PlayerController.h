#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "CFR_PlayerController.generated.h"

class UInputAction;

class UCFR_InGameWidgetManager;
class UCFR_IHUDWidget;
class UCFR_IPauseMenuWidget;
class UCFR_ISkipCutsceneWidget;

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

	FOnAnyInputAction OnAnyInputAction;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> HUDWidgetType;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UCFR_IPauseMenuWidget> PauseMenuWidgetType;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UCFR_ISkipCutsceneWidget> SkipCutsceneWidgetType;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> PlayerWinsWidgetType;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> PlayerLosesWidgetType;
	
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

	TObjectPtr<UCFR_InGameWidgetManager> HUDWidgetManager;
};
