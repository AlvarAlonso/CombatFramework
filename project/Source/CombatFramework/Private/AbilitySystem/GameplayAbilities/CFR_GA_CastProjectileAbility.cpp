// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GameplayAbilities/CFR_GA_CastProjectileAbility.h"
#include "AbilitySystem/CFR_BlueprintFunctionLibrary.h"
#include "Characters/CFR_CharacterBase.h"
#include "Kismet/KismetMathLibrary.h"

void UCFR_GA_CastProjectileAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
    const ACFR_CharacterBase* Character = Cast<ACFR_CharacterBase>(ActorInfo->AvatarActor);
    if (Character)
    {
        TeamIdToApply = Character->GetGenericTeamId();
    }

    Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UCFR_GA_CastProjectileAbility::OnReceivedEvent(FGameplayTag EventTag, FGameplayEventData EventData)
{
    FProjectileSpawnData ProjectileSpawnData;
    ProjectileSpawnData.SourceActor = GetAvatarActorFromActorInfo();
    ProjectileSpawnData.TargetActor = EventData.Target.Get();
    ProjectileSpawnData.TeamId = TeamIdToApply;
    ProjectileSpawnMethod->Spawn_Implementation(ProjectileSpawnData);
}

void UCFR_GA_CastProjectileAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
    Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

// TODO: Place that into some file.
static FTransform GetSpawnTransform(const AActor* SourceActor, const AActor* TargetActor)
{
    // TODO: Get exact spawn place from local spawned object instead of hardcoding it like that.
    const ACFR_CharacterBase* Character = Cast<ACFR_CharacterBase>(SourceActor);
    const FVector Location = Character->GetActorLocation();
    const FVector Direction = TargetActor ? UKismetMathLibrary::GetDirectionUnitVector(Location, TargetActor->GetActorLocation()) : Character->GetActorForwardVector();
    
    return FTransform(Direction.Rotation(), Location, FVector(1.0f));
}

bool UCFR_ClusteredSpawn::Spawn_Implementation(const FProjectileSpawnData& ProjectileSpawnData)
{
    return false;
}

bool UCFR_BurstSpawn::Spawn_Implementation(const FProjectileSpawnData& ProjectileSpawnData)
{
    const auto SourceActor = ProjectileSpawnData.SourceActor;
    const auto TargetActor = ProjectileSpawnData.TargetActor;
    const FTransform SpawnTransform = GetSpawnTransform(SourceActor, TargetActor);

    const auto Projectile = ProjectileSpawnData.Projectile;
    const auto TeamId = ProjectileSpawnData.TeamId;
    const auto SpawnedProjectile = UCFR_BlueprintFunctionLibrary::SpawnProjectile(GetWorld(), Projectile, SpawnTransform, SourceActor, TeamId);
    if (SpawnedProjectile)
    {
        ++NumProjectilesToFire;
        return true;
    }

    return false;
}
