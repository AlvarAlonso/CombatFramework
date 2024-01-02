// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifies/CFR_ANS_JumpComboSection.h"

#include "InputAction.h"

#include "AbilitySystem/CFR_AbilitySystemComponent.h"
#include "Characters/CFR_CharacterBase.h"

void UCFR_ANS_JumpComboSection::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Character = Cast<ACFR_CharacterBase>(MeshComp->GetOwner());
	if (Character)
	{
		ASC = Cast<UCFR_AbilitySystemComponent>(Character->GetAbilitySystemComponent());
		if (IsValid(ASC))
		{
			// TODO: Generic solution for every character, not only players.
			ASC->AddUniqueLooseGameplayTag(FGameplayTag::RequestGameplayTag("Combo.CanCombo"));
			InputReceivedDelegateHandle = ASC->OnInputActionStarted.AddLambda([this](UInputAction* PressedInputAction)
				{
					if (ASC)
					{
						if (InputAction == PressedInputAction)
						{
							FGameplayTag Tag = FGameplayTag::RequestGameplayTag("Combo.ContinueCombo");
							ASC->AddUniqueLooseGameplayTag(Tag);
						}
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("Can't continue combo. ASC is not valid."));
					}
				});
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Owner in function %s in %s has not a valid UAbilitySystemComponent."), *FString(__FUNCTION__), *GetClass()->GetName());
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Owner of MeshComp in function %s in %s is not a ACFR_CharacterBase!"), *FString(__FUNCTION__), *GetClass()->GetName());
	}
}

void UCFR_ANS_JumpComboSection::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime)
{
	if (IsValid(Character) && IsValid(ASC))
	{
		bool bCanCombo = ASC->HasMatchingGameplayTag(FGameplayTag::RequestGameplayTag("Combo.CanCombo"));
		bool bCanJumpToComboSection = ASC->HasMatchingGameplayTag(FGameplayTag::RequestGameplayTag("Combo.CanJumpToComboSection"));
		bool bContinueCombo = ASC->HasMatchingGameplayTag(FGameplayTag::RequestGameplayTag("Combo.ContinueCombo"));
		bool bJumpToNextSection = bCanCombo && bCanJumpToComboSection && bContinueCombo;
		if (bJumpToNextSection)
		{
			UE_LOG(LogTemp, Display, TEXT("Jumping to next combo section."));
			Character->GetMesh()->GetAnimInstance()->Montage_JumpToSection(SectionName);
		}
	}
}

void UCFR_ANS_JumpComboSection::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (IsValid(Character) && IsValid(ASC))
	{
		// Remove combo related tags.
		ASC->OnInputActionStarted.Remove(InputReceivedDelegateHandle);
		ASC->RemoveLooseGameplayTag(FGameplayTag::RequestGameplayTag("Combo.CanCombo"));
		ASC->RemoveLooseGameplayTag(FGameplayTag::RequestGameplayTag("Combo.CanJumpToComboSection"));
		ASC->RemoveLooseGameplayTag(FGameplayTag::RequestGameplayTag("Combo.ContinueCombo"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Owner in function %s in %s has not a valid UAbilitySystemComponent."), *FString(__FUNCTION__), *GetClass()->GetName());
	}
}
