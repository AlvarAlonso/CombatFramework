#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "Templates/SharedPointer.h"
#include "GameplayEffect.h"

#include "AbilitySystem/CFR_AbilitySourceDataInterface.h"
#include "AbilitySystem/CFR_GameplayTags.h"

#include "CFR_EventDataPayloads.generated.h"


UCLASS()
class UCFR_EventDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FGameplayTag EventTag;

public:
	FGameplayTag GetEventTag() { return EventTag; }
};

USTRUCT(BlueprintType)
struct FCFR_EffectContextContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> EffectToApply;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UCFR_EventDataAsset* Payload;
};

UCLASS(BlueprintType)
class UCFR_DamageEventDataAsset : public UCFR_EventDataAsset, public ICFR_AbilitySourceDataInterface
{
	GENERATED_BODY()

	UCFR_DamageEventDataAsset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) {}

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName DamageCurveName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName AttributeScalingCurveName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UCurveTable* DamageLevelCurve = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag HitReact;
};

UCLASS(BlueprintType)
class UCFR_LaunchEventDataAsset : public UCFR_EventDataAsset
{
	GENERATED_BODY()

public:
	UCFR_LaunchEventDataAsset(){
		EventTag = FCFR_GameplayTags::Get().GameplayEffect_Launch;
	}

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float LaunchHorizontalForce;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float LaunchVerticalForce;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bOverrideHorizontal;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bOverrideVertical;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bInstigatorOrigin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bKnockUp;
};

