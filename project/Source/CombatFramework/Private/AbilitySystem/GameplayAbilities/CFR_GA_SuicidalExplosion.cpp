// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GameplayAbilities/CFR_GA_SuicidalExplosion.h"
#include "AbilitySystem/CFR_AbilitySystemGlobals.h"
#include "Characters/CFR_CharacterBase.h"

#include "Kismet/KismetSystemLibrary.h"
#include "AbilitySystemGlobals.h"
#include "AbilitySystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"


bool UCFR_GA_SuicidalExplosion::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, OUT FGameplayTagContainer* OptionalRelevantTags) const
{
	const ACFR_CharacterBase* Character = Cast<ACFR_CharacterBase>(GetAvatarActorFromActorInfo());

	return Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags) && Character;
}

void UCFR_GA_SuicidalExplosion::OnReceivedEvent(FGameplayTag EventTag, FGameplayEventData EventData)
{
	Super::OnReceivedEvent(EventTag, EventData);

	if (EventTag.MatchesTagExact(FCFR_GameplayTags::Get().GameplayEvent_Explode))
	{
		Explode();
	}
}

// TODO: Could it be a generic reusable function and be put in a function library?
void UCFR_GA_SuicidalExplosion::Explode()
{
	const FVector SpawnLocation = CurrentActorInfo->AvatarActor->GetActorLocation();
	const FRotator SpawnRotation = FRotator(0.0f);

	TArray<TEnumAsByte<EObjectTypeQuery>> TraceObjectTypes;
	TraceObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));

	TArray<AActor*> IgnoreActors;
	TArray<AActor*> OutActors;

	// This is not going throw all our hitbox logic. Could be a way to make all target data to go through same interface?
	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), SpawnLocation, ExplosionRadius, TraceObjectTypes, nullptr, IgnoreActors, OutActors);
	
	const ACFR_CharacterBase* OwnerCharacter = Cast<ACFR_CharacterBase>(GetAvatarActorFromActorInfo());

	for (AActor* Actor : OutActors)
	{
		const ACFR_CharacterBase* Character = Cast<ACFR_CharacterBase>(Actor);
		if (Character)
		{
			FGameplayEventData EventPayload;
			EventPayload.Instigator = CurrentActorInfo->AvatarActor.Get();
			EventPayload.OptionalObject = LaunchEventData;

			UAbilitySystemComponent* SourceASC = GetAbilitySystemComponentFromActorInfo();
			UAbilitySystemComponent* TargetASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Actor);
				
			ApplyGameplayEffectsFromTag(FCFR_GameplayTags::Get().GameplayEvent_Explode, OwnerCharacter, SourceASC, TargetASC);
		}
	}

	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ExplosionVFX, SpawnLocation, SpawnRotation);

	FGameplayEventData DeadEventPayload;
	GetAbilitySystemComponentFromActorInfo()->ApplyGameplayEffectToSelf(InstantDeathEffect->GetDefaultObject<UGameplayEffect>(), 1, GetAbilitySystemComponentFromActorInfo()->MakeEffectContext());
}
