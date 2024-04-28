#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"

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
	UCFR_EventDataAsset* Payload = nullptr;
};

UCLASS(BlueprintType)
class UCFR_DamageEventDataAsset : public UCFR_EventDataAsset
{
	GENERATED_BODY()

public:
	// TODO: Table information about the damage to apply.
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Damage;
};