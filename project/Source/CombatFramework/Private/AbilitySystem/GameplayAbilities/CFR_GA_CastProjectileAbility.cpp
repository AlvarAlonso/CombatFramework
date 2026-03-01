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

bool UCFR_ClusteredSpawn::Spawn_Implementation(const FProjectileSpawnData& ProjectileSpawnData)
{
    const auto SourceActor = ProjectileSpawnData.SourceActor;

    ACFR_CharacterBase* Character = Cast<ACFR_CharacterBase>(SourceActor);
    if (Character)
    {
        // TODO: SetFocus(nullptr) in character controller.

        const FVector Forward = Character->GetActorForwardVector();
        const FVector Right = Character->GetActorRightVector();
        const FVector Up = Character->GetActorUpVector();
        const FVector Center = Character->GetActorLocation();
        FTransform SpawnTransform = FTransform(Forward.Rotation(), Center, FVector(1.0f));
       
        // Generate spawn positions.
        TArray<FVector> PointsToSpawn;
        PointsToSpawn.Reserve(NumProjectilesToFire);
        for (int i = 0; i < NumProjectilesToFire; ++i)
        {
            FVector2D Point2D = FMath::RandPointInCircle(ClusterRadius);
            FVector Position;
            Position.X = Right.X * Point2D.X;
            Position.Y = Right.Y * Point2D.Y;
            Position.Z = FMath::RandRange(MinSpawnDistance, MaxSpawnDistance);
            Position = Center + Position;
            PointsToSpawn.Emplace(Position);
        }

        // Spawn projectiles.
        for (const auto& Point : PointsToSpawn)
        {
            SpawnTransform.SetTranslation(Point);
            const auto SpawnedProjectile = UCFR_BlueprintFunctionLibrary::SpawnProjectile(
                GetWorld(), 
                ProjectileSpawnData.Projectile, 
                SpawnTransform, 
                ProjectileSpawnData.SourceActor, 
                ProjectileSpawnData.TeamId);
        }

        return true;
    }

    return false;
}

bool UCFR_BurstSpawn::Spawn_Implementation(const FProjectileSpawnData& ProjectileSpawnData)
{
    const auto SourceActor = ProjectileSpawnData.SourceActor;
    const auto TargetActor = ProjectileSpawnData.TargetActor;

    // TODO: Get exact spawn place from local spawned object instead of hardcoding it like that.
    const ACFR_CharacterBase* Character = Cast<ACFR_CharacterBase>(SourceActor);
    const FVector Location = Character->GetActorLocation();
    const FVector Direction = TargetActor ? UKismetMathLibrary::GetDirectionUnitVector(Location, TargetActor->GetActorLocation()) : Character->GetActorForwardVector();
    const FTransform SpawnTransform = FTransform(Direction.Rotation(), Location, FVector(1.0f));

    const auto Projectile = ProjectileSpawnData.Projectile;
    const auto TeamId = ProjectileSpawnData.TeamId;
    const auto SpawnedProjectile = UCFR_BlueprintFunctionLibrary::SpawnProjectile(
        GetWorld(), 
        Projectile, 
        SpawnTransform, 
        SourceActor, 
        TeamId);

    if (SpawnedProjectile)
    {
        ++NumProjectilesToFire;
        return true;
    }

    return false;
}
