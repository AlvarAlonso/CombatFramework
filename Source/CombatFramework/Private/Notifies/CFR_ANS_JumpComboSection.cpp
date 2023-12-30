// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifies/CFR_ANS_JumpComboSection.h"

#include "InputAction.h"

#include "AbilitySystem/CFR_AbilitySystemComponent.h"
#include "Characters/CFR_CharacterBase.h"

void UCFR_ANS_JumpComboSection::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	ACFR_CharacterBase* Character = Cast<ACFR_CharacterBase>(MeshComp->GetOwner());
	if (Character)
	{
		UCFR_AbilitySystemComponent* ASC = Cast<UCFR_AbilitySystemComponent>(Character->GetAbilitySystemComponent());
		if (ASC)
		{
			// TODO: Generic solution for every character, not only players.
			ASC->AddLooseGameplayTag(FGameplayTag::RequestGameplayTag("Combo.CanCombo"));
			ASC->OnInputActionStarted.AddLambda([this, &ASC](UInputAction* PressedInputAction)
				{
					if (InputAction == PressedInputAction)
					{
						UE_LOG(LogTemp, Display, TEXT("ContinueCombo!!!"));
						ASC->AddLooseGameplayTag(FGameplayTag::RequestGameplayTag("Combo.ContinueCombo"));
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
	ACFR_CharacterBase* Character = Cast<ACFR_CharacterBase>(MeshComp->GetOwner());
	if (Character)
	{
		UCFR_AbilitySystemComponent* ASC = Cast<UCFR_AbilitySystemComponent>(Character->GetAbilitySystemComponent());
		if (ASC)
		{
			bool bCanCombo = ASC->HasMatchingGameplayTag(FGameplayTag::RequestGameplayTag("Combo.CanCombo"));
			bool bCanJumpToComboSection = ASC->HasMatchingGameplayTag(FGameplayTag::RequestGameplayTag("Combo.CanJumpToComboSection"));
			bool bContinueCombo = ASC->HasMatchingGameplayTag(FGameplayTag::RequestGameplayTag("Combo.ContinueCombo"));
			bool bJumpToNextSection = bCanCombo && bCanJumpToComboSection && bContinueCombo;
			if (bJumpToNextSection)
			{
				Character->GetMesh()->GetAnimInstance()->Montage_JumpToSection(SectionName);
			}
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

void UCFR_ANS_JumpComboSection::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	ACFR_CharacterBase* Character = Cast<ACFR_CharacterBase>(MeshComp->GetOwner());
	if (Character)
	{
		UCFR_AbilitySystemComponent* ASC = Cast<UCFR_AbilitySystemComponent>(Character->GetAbilitySystemComponent());
		if (ASC)
		{
			// Remove combo related tags.
			ASC->RemoveLooseGameplayTag(FGameplayTag::RequestGameplayTag("Combo.CanCombo"));
			ASC->RemoveLooseGameplayTag(FGameplayTag::RequestGameplayTag("Combo.CanJumpToComboSection"));
			ASC->RemoveLooseGameplayTag(FGameplayTag::RequestGameplayTag("Combo.ContinueCombo"));
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
