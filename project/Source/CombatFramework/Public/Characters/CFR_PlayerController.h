#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "CFR_PlayerController.generated.h"

class UInputAction;

class UCFR_IHUDWidget;

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

	TObjectPtr<UCFR_IHUDWidget> HUDWidget;

private:
	void HandlePauseGameInput();

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
	TSubclassOf<UCFR_IHUDWidget> HUDWidgetType;
};
