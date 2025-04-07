// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "GenericTeamAgentInterface.h"
#include "CFR_CharacterBase.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
struct FOnAttributeChangeData;

UCLASS()
class COMBATFRAMEWORK_API ACFR_CharacterBase : public ACharacter, public IAbilitySystemInterface, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	ACFR_CharacterBase();

	UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual bool IsAlive() const;

	UFUNCTION(BlueprintCallable)
	virtual float GetHealth() const;

	UFUNCTION(BlueprintCallable)
	virtual float GetMaxHealth() const;

protected:

	virtual void Falling() override;
	virtual void Landed(const FHitResult& Hit) override;

	/* Must be called to initialize all GAS information related to this specific actor. */
	virtual void InitAbilitySystemInfo() PURE_VIRTUAL(ACFR_CharacterBase::InitAbilitySystemInfo, );
	virtual void HandleDeath();
	virtual void HandleHealthChanged(const FOnAttributeChangeData& InData);

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
