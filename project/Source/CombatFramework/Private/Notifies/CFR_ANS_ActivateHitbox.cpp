#include "Notifies/CFR_ANS_ActivateHitbox.h"
#include "Components/CFR_HitboxesManagerComponent.h"
#include "Components/CFR_HitboxComponent.h"

void UCFR_ANS_ActivateHitbox::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	AActor* Owner = MeshComp->GetOwner();

	if (auto HitboxesManagerComp = Owner ? Owner->FindComponentByClass<UCFR_HitboxesManagerComponent>() : nullptr)
	{
		if (auto Hitbox = HitboxesManagerComp->GetHitboxByTag(HitboxTag))
		{
			UE_LOG(LogTemp, Warning, TEXT("ACTIVATE!"));
			Hitbox->SetEffectTag(EffectTag);
			Hitbox->ActivateHitbox();
		}
	}
}

void UCFR_ANS_ActivateHitbox::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	AActor* Owner = MeshComp->GetOwner();

	if (auto HitboxesManagerComp = Owner ? Owner->FindComponentByClass<UCFR_HitboxesManagerComponent>() : nullptr)
	{
		if (auto Hitbox = HitboxesManagerComp->GetHitboxByTag(HitboxTag))
		{
			UE_LOG(LogTemp, Warning, TEXT("DEACTIVATE!"));
			Hitbox->DeactivateHitbox();
			Hitbox->SetEffectTag(FGameplayTag());
		}
	}
}
