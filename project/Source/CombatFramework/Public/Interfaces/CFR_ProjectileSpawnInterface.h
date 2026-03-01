// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Projectiles/CFR_Projectile.h"
#include "GenericTeamAgentInterface.h"
#include "UObject/Interface.h"

#include "CFR_ProjectileSpawnInterface.generated.h"

USTRUCT(BlueprintType)
struct FProjectileSpawnData
{
	GENERATED_USTRUCT_BODY()

public:
	AActor* SourceActor;
	const AActor* TargetActor;
	TSubclassOf<ACFR_Projectile> Projectile;
	FGenericTeamId TeamId;
};


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCFR_ProjectileSpawnInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class COMBATFRAMEWORK_API ICFR_ProjectileSpawnInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool Spawn(const FProjectileSpawnData& ProjectileSpawnData);
	virtual bool Spawn_Implementation(const FProjectileSpawnData& ProjectileSpawnData) = 0;
};

UCLASS(EditInlineNew, Blueprintable, Abstract)
class COMBATFRAMEWORK_API UCFR_ProjectileSpawnBase : public UObject, public ICFR_ProjectileSpawnInterface
{
	GENERATED_BODY()

public:
	virtual bool Spawn_Implementation(const FProjectileSpawnData& ProjectileSpawnData) override { return false; };
};
