// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifies/CFR_ANS_ActivateHitbox.h"
#include "Components/CFR_HitboxesManagerComponent.h"
#include "Components/CFR_HitboxComponent.h"

void UCFR_ANS_ActivateHitbox::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	AActor* Owner = MeshComp->GetOwner();

	UCFR_HitboxesManagerComponent* HitboxesManagerComp = Owner ? Owner->FindComponentByClass<UCFR_HitboxesManagerComponent>() : nullptr;
	if (HitboxesManagerComp)
	{
		UCFR_HitboxComponent* Hitbox = HitboxesManagerComp->GetHitboxByTag(HitboxTag);
		if (Hitbox)
		{
			Hitbox->ActivateHitbox(true);
		}
	}
}

void UCFR_ANS_ActivateHitbox::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	AActor* Owner = MeshComp->GetOwner();

	UCFR_HitboxesManagerComponent* HitboxesManagerComp = Owner ? Owner->FindComponentByClass<UCFR_HitboxesManagerComponent>() : nullptr;
	if (HitboxesManagerComp)
	{
		UCFR_HitboxComponent* Hitbox = HitboxesManagerComp->GetHitboxByTag(HitboxTag);
		if (Hitbox)
		{
			Hitbox->ActivateHitbox(false);
		}
	}
}
