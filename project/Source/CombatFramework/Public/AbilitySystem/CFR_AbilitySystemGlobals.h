// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemGlobals.h"
#include "GameplayEffectTypes.h"
#include "CFR_AbilitySystemGlobals.generated.h"

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_AbilitySystemGlobals : public UAbilitySystemGlobals
{
	GENERATED_BODY()
	
public:
	static UCFR_AbilitySystemGlobals& UCFRGet()
	{
		return dynamic_cast<UCFR_AbilitySystemGlobals&>(Get());
	}

	FGameplayEffectContext* AllocGameplayEffectContext() const override;
};

USTRUCT(BlueprintType)
struct COMBATFRAMEWORK_API FCFR_GameplayEffectContext : public FGameplayEffectContext
{
	GENERATED_USTRUCT_BODY()

public:
	UScriptStruct* GetScriptStruct() const override
	{
		return FCFR_GameplayEffectContext::StaticStruct();
	}

	FCFR_GameplayEffectContext* Duplicate() const override
	{
		FCFR_GameplayEffectContext* NewContext = new FCFR_GameplayEffectContext();
		*NewContext = *this;
		NewContext->AddActors(Actors);
		if (GetHitResult())
		{
			// Does a deep copy of the hit result
			NewContext->AddHitResult(*GetHitResult(), true);
		}

		return NewContext;
	}

	bool NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess) override;

public:
	// Payload. Object with the EventDataAsset.
	UPROPERTY()
	TWeakObjectPtr<const UObject> AbilitySourceData;
};

template<>
struct TStructOpsTypeTraits<FCFR_GameplayEffectContext> : public TStructOpsTypeTraitsBase2<FCFR_GameplayEffectContext>
{
	enum
	{
		WithNetSerializer = true,
		WithCopy = true		// Necessary so that TSharedPtr<FHitResult> Data is copied around
	};
};