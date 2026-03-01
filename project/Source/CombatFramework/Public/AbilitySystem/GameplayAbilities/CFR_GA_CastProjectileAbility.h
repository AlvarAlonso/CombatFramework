// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"

#include "AbilitySystem/GameplayAbilities/CFR_GA_PlayMontage.h"
#include "Actors/Projectiles/CFR_Projectile.h"
#include "Interfaces/CFR_ProjectileSpawnInterface.h"

#include "CFR_GA_CastProjectileAbility.generated.h"

UENUM(BlueprintType)
enum class ECFR_SpawnMethod : uint8
{
	None		UMETA(DisplayName = "None"),
	Burst		UMETA(DisplayName = "Burst"),
	Clustered	UMETA(DisplayName = "Clustered")
};

UCLASS(EditInlineNew, Blueprintable)
class COMBATFRAMEWORK_API UCFR_BurstSpawn : public UCFR_ProjectileSpawnBase
{
	GENERATED_BODY()

	UCFR_BurstSpawn() :
		CurrentSpawnedProjectiles(0) {};

public:
	virtual bool Spawn_Implementation(const FProjectileSpawnData& ProjectileSpawnData) override;

public:
	UPROPERTY(EditAnywhere)
	int NumProjectilesToFire;

private:
	int CurrentSpawnedProjectiles;
};

UCLASS(EditInlineNew, Blueprintable)
class COMBATFRAMEWORK_API UCFR_ClusteredSpawn : public UCFR_ProjectileSpawnBase
{
	GENERATED_BODY()

public:
	virtual bool Spawn_Implementation(const FProjectileSpawnData& ProjectileSpawnData) override;

public:
	UPROPERTY(EditAnywhere)
	int NumProjectilesToFire;
};

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_GA_CastProjectileAbility : public UCFR_GA_PlayMontage
{
	GENERATED_BODY()
	
protected:
	void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;

	virtual void OnReceivedEvent(
		FGameplayTag EventTag,
		FGameplayEventData EventData);

	void EndAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		bool bReplicateEndAbility,
		bool bWasCancelled) override;

protected:
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ACFR_Projectile> ProjectileBP;

	UPROPERTY(EditDefaultsOnly, Instanced, meta = (AllowPrivateAccess = "true"))
	UCFR_ProjectileSpawnBase* ProjectileSpawnMethod;

	FGenericTeamId TeamIdToApply;
	FTransform SpawnTransform;
};
