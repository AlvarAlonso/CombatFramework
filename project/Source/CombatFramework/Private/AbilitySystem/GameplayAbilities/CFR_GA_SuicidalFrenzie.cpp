// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GameplayAbilities/CFR_GA_SuicidalFrenzie.h"
#include "Characters/CFR_CharacterBase.h"

#include "Components/MeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "NiagaraComponent.h"

bool UCFR_GA_SuicidalFrenzie::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, OUT FGameplayTagContainer* OptionalRelevantTags) const
{
    // TODO: Define what we need to activate abilities in general. Do we only apply them to CharacterBase?

    ACFR_CharacterBase* Character = Cast<ACFR_CharacterBase>(GetAvatarActorFromActorInfo());

    return Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags) && Character;
}

void UCFR_GA_SuicidalFrenzie::OnReceivedEvent(FGameplayTag EventTag, FGameplayEventData EventData)
{
    if (EventTag.MatchesTagExact(FCFR_GameplayTags::Get().GameplayEvent_Frenzied))
    {
        ACFR_CharacterBase* Character = Cast<ACFR_CharacterBase>(GetAvatarActorFromActorInfo());
        if (Character)
        {
            UCharacterMovementComponent* CharacterMovementComponent = Character->GetCharacterMovement();
            if (CharacterMovementComponent)
            {
                // TODO: Speed should not be changed directly like this. It is not safe and prone to bugs.
                // What if the speed is being modified at the same time by another ability or effect?
                CharacterMovementComponent->MaxWalkSpeed *= FrenzieSpeedMultiplier;
                UMeshComponent* MeshComponent = Character->GetMesh();
                if (MeshComponent)
                {
                    MeshComponent->SetMaterial(0, FrenziedMaterial);
                }

                UNiagaraComponent* NiagaraComponent = Character->FindComponentByClass<UNiagaraComponent>();
                if (NiagaraComponent)
                {
                    NiagaraComponent->Activate();
                }
            }
        }
    }
}
