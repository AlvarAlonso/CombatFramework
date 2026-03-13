#include "Components/CFR_HitboxComponent.h"

#include "AbilitySystemGlobals.h"
#include "AbilitySystemComponent.h"
#include "GenericTeamAgentInterface.h"

#include "Characters/CFR_CharacterBase.h"
#include "Characters/CFR_PlayerCharacter.h"
#include "Components/ShapeComponent.h"

UCFR_HitboxComponent::UCFR_HitboxComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UCFR_HitboxComponent::BeginPlay()
{
	Super::BeginPlay();

	// TODO: Try to attach the colliders in the editor instead of begin play.
	// Get references to all children colliders (colliders that represent the hitbox).
	TArray<USceneComponent*> Children;
	GetChildrenComponents(false, Children);
	for (USceneComponent* Child : Children)
	{
		UShapeComponent* ShapeComponent = Cast<UShapeComponent>(Child);
		if (ShapeComponent)
		{
			Shapes.Add(ShapeComponent);
		}
	}

	// Delegate Shape OnComponentBeginOverlap to custom OnComponentOverlap.
	for (UShapeComponent* Shape : Shapes)
	{
		Shape->OnComponentBeginOverlap.AddDynamic(this, &UCFR_HitboxComponent::OnComponentOverlap);
	}

	if (bStartActive)
	{
		ActivateHitbox();
	}
	else
	{
		DeactivateHitbox();
	}
}

void UCFR_HitboxComponent::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	for (UShapeComponent* Shape : Shapes)
	{
		Shape->OnComponentBeginOverlap.RemoveDynamic(this, &UCFR_HitboxComponent::OnComponentOverlap);
	}
}

void UCFR_HitboxComponent::OnComponentOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// TODO: Should not be hardcoded to hostile. An ability should be able to activate a hitbox especifying whose the target.
	ETeamAttitude::Type Attitude = FGenericTeamId::GetAttitude(this->GetOwner(), OtherActor);
	if (Attitude == ETeamAttitude::Hostile)
	{
		if (auto player = Cast<ACFR_PlayerCharacter>(GetOwner()))
		{
			player->UpdateMana();
		}

		// If checks are passed, handle the collision.
		HandleOverlappedActor(OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	}
}

void UCFR_HitboxComponent::HandleOverlappedActor(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("HitboxComponent: HandleOverlappedActor"));
	SendCollisionEvents(OtherActor);
}

void UCFR_HitboxComponent::ActivateHitbox()
{
	for (UShapeComponent* Shape : Shapes)
	{
		Shape->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}
}

void UCFR_HitboxComponent::DeactivateHitbox()
{
	for (UShapeComponent* Shape : Shapes)
	{
		// Using directly SetCollisionEnabled causes a bug.
		Shape->GetBodyInstance()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

void UCFR_HitboxComponent::SetEffectTag(FGameplayTag Tag)
{
	EffectTag = Tag;
}

FGameplayTag UCFR_HitboxComponent::GetEffectTag() const
{
	return EffectTag;
}

void UCFR_HitboxComponent::SendCollisionEvents(AActor* TargetActor)
{
	if (const auto OwnerCharacter = Cast<ACFR_CharacterBase>(GetOwner()))
	{
		if (auto OwnerASC = OwnerCharacter->GetAbilitySystemComponent())
		{
			FGameplayEventData* EventData = new FGameplayEventData();
			EventData->Instigator = OwnerCharacter;
			EventData->Target = TargetActor;

			OwnerASC->HandleGameplayEvent(EffectTag, EventData);
		}
	}

	if (OnHitboxOverlap.IsBound())
	{
		OnHitboxOverlap.Broadcast(TargetActor);
	}
}

