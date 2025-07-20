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
class UCFR_LaunchEventDataAsset;
class UCFR_MovementAssistComponent;

DECLARE_MULTICAST_DELEGATE_OneParam(FOnHandleDeath, class ACFR_CharacterBase*);

UCLASS()
class COMBATFRAMEWORK_API ACFR_CharacterBase : public ACharacter, public IAbilitySystemInterface, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	ACFR_CharacterBase();

	// IAbilitySystemInterface
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	FOnHandleDeath OnHandleDeathEvent;

	virtual bool IsAlive() const;

	UFUNCTION(BlueprintCallable)
	virtual float GetHealth() const;

	UFUNCTION(BlueprintCallable)
	virtual float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable)
	float GetCharacterLevel() const;

	UFUNCTION(BlueprintCallable)
	void PushCharacter(AActor* ActorInstigator, const UCFR_LaunchEventDataAsset* LaunchPayload);

	bool GetIsActive() const;

	void Die();

protected:

	virtual void Falling() override;
	virtual void Landed(const FHitResult& Hit) override;
	virtual bool CanBeLaunched(AActor* ActorInstigator, const UCFR_LaunchEventDataAsset* LaunchPayload);

	/* Must be called to initialize all GAS information related to this specific actor. */
	virtual void InitAbilitySystemInfo() PURE_VIRTUAL(ACFR_CharacterBase::InitAbilitySystemInfo, );
	virtual void HandleStartDying();
	virtual void OnDeathMontageEnded(UAnimMontage* Montage, bool bInterrupted);
	/* Should be called by Death Anim Montage. */
	UFUNCTION(BlueprintCallable)
	void NotifyDeath();
	virtual void HandleFinishDying();
	virtual void HandleHealthChanged(const FOnAttributeChangeData& InData);

	/** The level of this character, should not be modified directly once it has already spawned */
	UPROPERTY(EditAnywhere, Category = Abilities)
	float CharacterLevel;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UCFR_MovementAssistComponent> MovementAssistComponent;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	/** If vertical forces can be applied to the actor or not */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bCanBeKnockup = true;

private:
	friend class UCFR_PoolSubsystem;

	bool bIsActive{ false };
	FOnMontageEnded DeathMontageEndedDelegate;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UAnimMontage> DeathMontage;
};
