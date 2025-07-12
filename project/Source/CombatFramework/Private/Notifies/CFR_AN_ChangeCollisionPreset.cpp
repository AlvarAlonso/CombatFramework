// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifies/CFR_AN_ChangeCollisionPreset.h"
#include "Characters/CFR_CharacterBase.h"
#include "Components/CapsuleComponent.h"

void UCFR_AN_ChangeCollisionPreset::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	const AActor* Owner = MeshComp->GetOwner();

	const ACFR_CharacterBase* CharacterBase = Cast<ACFR_CharacterBase>(Owner);
	if (CharacterBase)
	{
		CharacterBase->GetCapsuleComponent()->SetCollisionResponseToChannel(NewCollisionChannel, NewCollisionResponse);
	}
}
