#pragma once

#include "AbilitySystem/CFR_GameplayAbility.h"

#include "CFR_GA_Spear.generated.h"

class ACFR_Spear;

UCLASS()
class UCFR_GA_Spear : public UCFR_GameplayAbility
{
	GENERATED_BODY()

protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

private:
	void CastSpears(AActor* InCasterActor);

	UPROPERTY(EditAnywhere)
	TSubclassOf<ACFR_Spear> SpearClass;

	UPROPERTY(EditDefaultsOnly, Category = "Spear")
	int MaxNumberOfSpears = 6;

	UPROPERTY(EditDefaultsOnly, Category = "Spear")
	float DistanceFromCaster = 200.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Spear")
	float SpearAngle = 180.0f;

	UPROPERTY()
	TArray<TObjectPtr<ACFR_Spear>> Spears;
};
