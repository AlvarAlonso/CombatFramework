// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifies/CFR_ANS_JumpComboSection.h"

#include "AbilitySystem/CFR_AbilitySystemComponent.h"
#include "AbilitySystem/CFR_GameplayTags.h"
#include "Characters/CFR_CharacterBase.h"

#include "InputAction.h"

void UCFR_ANS_JumpComboSection::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Character = Cast<ACFR_CharacterBase>(MeshComp->GetOwner());
	if (Character)
	{
		ASC = Cast<UCFR_AbilitySystemComponent>(Character->GetAbilitySystemComponent());
		if (IsValid(ASC))
		{
			// TODO: Generic solution for every character, not only players.
			ASC->AddUniqueLooseGameplayTag(FCFR_GameplayTags::Get().Combo_CanCombo);
			InputReceivedDelegateHandle = ASC->OnInputActionStarted.AddLambda([this](UInputAction* PressedInputAction)
				{
					if (ASC)
					{
						if (InputAction == PressedInputAction)
						{
							FGameplayTag Tag = FCFR_GameplayTags::Get().Combo_ContinueCombo;
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
		bool bCanCombo = ASC->HasMatchingGameplayTag(FCFR_GameplayTags::Get().Combo_CanCombo);
		bool bCanJumpToComboSection = ASC->HasMatchingGameplayTag(FCFR_GameplayTags::Get().Combo_CanJumpToComboSection);
		bool bContinueCombo = ASC->HasMatchingGameplayTag(FCFR_GameplayTags::Get().Combo_ContinueCombo);
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
		ASC->RemoveLooseGameplayTag(FCFR_GameplayTags::Get().Combo_CanCombo);
		ASC->RemoveLooseGameplayTag(FCFR_GameplayTags::Get().Combo_CanJumpToComboSection);
		ASC->RemoveLooseGameplayTag(FCFR_GameplayTags::Get().Combo_ContinueCombo);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Owner in function %s in %s has not a valid UAbilitySystemComponent."), *FString(__FUNCTION__), *GetClass()->GetName());
	}
}
