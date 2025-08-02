// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include "GenericTeamAgentInterface.h"

#include "Interfaces/CFR_GameplayTagInterface.h"

#include "CFR_CharacterBase.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
struct FOnAttributeChangeData;
class UCFR_LaunchEventDataAsset;
class UCFR_MovementAssistComponent;
class UGameplayAbility;

DECLARE_MULTICAST_DELEGATE_OneParam(FOnHandleDeath, class ACFR_CharacterBase*);

UCLASS()
class COMBATFRAMEWORK_API ACFR_CharacterBase : public ACharacter, public IAbilitySystemInterface, public IGenericTeamAgentInterface, public IGameplayTagAssetInterface, public ICFR_GameplayTagInterface
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

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnDamageTaken();

	bool GetIsActive() const;

	void Die();

	/** GameplayTagAssetInterface methods */
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;
	virtual bool HasMatchingGameplayTag(FGameplayTag TagToCheck) const override;
	virtual bool HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override;
	virtual bool HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override;

	/** CFR_GameplayTagInterface methods */
	UFUNCTION()
	virtual void AddGameplayTag(const FGameplayTag& TagToAdd) override;
	UFUNCTION()
	virtual void RemoveGameplayTag(const FGameplayTag& TagToRemove, bool bCleanAll = false) override;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void Falling() override;
	virtual void Landed(const FHitResult& Hit) override;
	virtual bool CanBeLaunched(AActor* ActorInstigator, const UCFR_LaunchEventDataAsset* LaunchPayload);
	bool IsFallingDown();

	/* Must be called to initialize all GAS information related to this specific actor. */
	virtual void InitAbilitySystemInfo() PURE_VIRTUAL(ACFR_CharacterBase::InitAbilitySystemInfo, );
	/* Must be called after AbilitySystemComponent has been initialized in InitAbilitySystemInfo().*/
	void InitializeAbilitySystemComponentCallbacks();
	void HandleKnockedUp(const FGameplayTag CallbackTag, int32 NewCount);

	virtual void HandleStartDying();
	virtual void OnDeathMontageEnded(UAnimMontage* Montage, bool bInterrupted);
	/* Should be called by Death Anim Montage. */
	UFUNCTION(BlueprintCallable)
	void NotifyDeath();
	virtual void HandleFinishDying();
	virtual void HandleHealthChanged(const FOnAttributeChangeData& InData);

	void CheckKnockUpState();
	void HandleKnockedUpEnded();
	virtual void HandleAirAbilityActivated(UGameplayAbility* GameplayAbility);
	virtual void HandleAirAbilityEnded(UGameplayAbility* GameplayAbility);

	/** The level of this character, should not be modified directly once it has already spawned */
	UPROPERTY(EditAnywhere, Category = Abilities)
	float CharacterLevel;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UCFR_MovementAssistComponent> MovementAssistComponent;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	// TODO: Should we move everything no related to state, 
	// like base stats and immutable variables to a DataAsset to
	// separate it from implementation details?
	// TODO: Maybe some properties should be general while others be
	// set for every type of character.

	/** If vertical forces can be applied to the actor or not */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bCanBeKnockup = true;

	/** Time the gravity will remain 0 when the character 
		reaches the highest point of a knock up. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float TimeGravityZeroAfterKnockedUp = 0.3f;

	/* Character defaults that should be applied to the movement component. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MaxAcceleration = 2048.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float GravityScale = 3.0f;

private:
	friend class UCFR_PoolSubsystem;

	bool bIsActive{ false };
	FOnMontageEnded DeathMontageEndedDelegate;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UAnimMontage> DeathMontage;

	FDelegateHandle OnAirAbilityActivatedDelegateHandle;
	FDelegateHandle OnAirAbilityEndedDelegateHandle;
};
