// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTags.h"
#include "CFR_GameplayTagInterface.generated.h"

/** Interface for assets which contain gameplay tags */
UINTERFACE(MinimalAPI, NotBlueprintable)
class UCFR_GameplayTagInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class COMBATFRAMEWORK_API ICFR_GameplayTagInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = CFRGameplayTags)
	virtual void AddGameplayTag(const FGameplayTag& TagToAdd) = 0;

	UFUNCTION(BlueprintCallable, Category = CFRGameplayTags)
	virtual void RemoveGameplayTag(const FGameplayTag& TagToRemove, bool bCleanAll) = 0;
};
