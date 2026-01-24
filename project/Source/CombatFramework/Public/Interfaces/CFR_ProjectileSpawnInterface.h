// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CFR_ProjectileSpawnInterface.generated.h"

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
	bool Spawn();
	virtual bool Spawn_Implementation() = 0;
};

UCLASS(EditInlineNew, Blueprintable, Abstract)
class COMBATFRAMEWORK_API UCFR_ProjectileSpawnBase : public UObject, public ICFR_ProjectileSpawnInterface
{
	GENERATED_BODY()

public:
	virtual bool Spawn_Implementation() override { return false; };
};
