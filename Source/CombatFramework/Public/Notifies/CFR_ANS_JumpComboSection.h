// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "CFR_ANS_JumpComboSection.generated.h"

class UInputAction;
class ACFR_CharacterBase;
class UCFR_AbilitySystemComponent;

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_ANS_JumpComboSection : public UAnimNotifyState
{
	GENERATED_BODY()
	
public:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration) override;
	virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

public:
	/* Section name to jump when appropiate input is received. */
	UPROPERTY(EditAnywhere)
	FName SectionName;

	/* InputAction to be started to continue the combo. */
	UPROPERTY(EditAnywhere)
	UInputAction* InputAction = nullptr;

private:
	TObjectPtr<ACFR_CharacterBase> Character = nullptr;
	TObjectPtr<UCFR_AbilitySystemComponent> ASC = nullptr;

	FDelegateHandle InputReceivedDelegateHandle;
};
