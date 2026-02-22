#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "CFR_PlayerController.generated.h"

class UInputAction;
class UInputMappingContext;

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
	
private:
	void HandlePauseGameInput();
	void HandleSkipCutsceneInput();
	void HandleAnyInput();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* MappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* CinematicMappingContext;
	
	/** Input Actions */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* PauseGameAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* SkipCutsceneAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* AnyInputAction;
};
