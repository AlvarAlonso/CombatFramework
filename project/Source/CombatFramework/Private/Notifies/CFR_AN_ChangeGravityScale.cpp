// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifies/CFR_AN_ChangeGravityScale.h"
#include "Characters/CFR_CharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"

void UCFR_AN_ChangeGravityScale::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	const AActor* Owner = MeshComp->GetOwner();

	const ACFR_CharacterBase* CharacterBase = Cast<ACFR_CharacterBase>(Owner);
	if (CharacterBase)
	{
		UCharacterMovementComponent* CharacterMovementComponent = CharacterBase->GetCharacterMovement();
		if (CharacterMovementComponent)
		{
			CharacterMovementComponent->GravityScale = NewGravityScale;
		}
	}
}
