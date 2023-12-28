// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "CFR_AbilitySystemComponent.generated.h"

class UInputAction;
class UEnhancedInputComponent;

USTRUCT()
struct FCFR_AbilityInitData
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly)
    UInputAction* InputAction;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UGameplayAbility> Ability;
};

USTRUCT()
struct FCFR_AbilityInputBinding
{
    GENERATED_BODY()

    int32 InputID = 0;
    uint32 OnPressedHandle = 0;
    uint32 OnReleasedHandle = 0;
    FGameplayAbilitySpecHandle AbilitySpecHandle;
};

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_AbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public: 
    /* Can add abilities in game. */
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	FGameplayAbilitySpecHandle GrantAbilityOfType(TSubclassOf<UGameplayAbility> AbilityType, bool bRemoveAfterActivation);

    /* Gameplay Tags*/
    // Exposes AddLooseGameplayTag to Blueprint. This tag is *not* replicated.
    UFUNCTION(BlueprintCallable, Category = "Abilities", Meta = (DisplayName = "AddLooseGameplayTag"))
    void K2_AddLooseGameplayTag(const FGameplayTag& GameplayTag, int32 Count = 1);

    // Exposes AddLooseGameplayTags to Blueprint. These tags are *not* replicated.
    UFUNCTION(BlueprintCallable, Category = "Abilities", Meta = (DisplayName = "AddLooseGameplayTags"))
    void K2_AddLooseGameplayTags(const FGameplayTagContainer& GameplayTags, int32 Count = 1);

    // Exposes RemoveLooseGameplayTag to Blueprint. This tag is *not* replicated.
    UFUNCTION(BlueprintCallable, Category = "Abilities", Meta = (DisplayName = "RemoveLooseGameplayTag"))
    void K2_RemoveLooseGameplayTag(const FGameplayTag& GameplayTag, int32 Count = 1);

    // Exposes RemoveLooseGameplayTags to Blueprint. These tags are *not* replicated.
    UFUNCTION(BlueprintCallable, Category = "Abilities", Meta = (DisplayName = "RemoveLooseGameplayTags"))
    void K2_RemoveLooseGameplayTags(const FGameplayTagContainer& GameplayTags, int32 Count = 1);
    /* ---------------------------- */

    void GrantDefaultAbilities();

    /* Input */
    UFUNCTION(BlueprintCallable, Category = "Input")
    void SetInputBinding(UInputAction* InputAction, FGameplayAbilitySpecHandle AbilitySpecHandle);
    /* ---------------------------- */

protected:
    virtual void BeginPlay() override;

private:
    /* Input */
    void OnAbilityInputStarted(UInputAction* InputAction);

    void OnAbilityInputCompleted(UInputAction* InputAction);

    void RemoveInputBinding(UInputAction* InputAction);

    void TryBindAbilityInput(UInputAction* InputAction, FCFR_AbilityInputBinding& AbilityInputBinding);
    /* ---------------------------- */

public:
    UPROPERTY(EditDefaultsOnly, Category = "Abilities")
    TArray<FCFR_AbilityInitData> DefaultAbilitiesInitData;

protected:
    TArray<FGameplayAbilitySpecHandle> DefaultAbilityHandles;

    TMap<UInputAction*, FCFR_AbilityInputBinding> AbilitiesBindingInfo;

    UPROPERTY(transient)
    UEnhancedInputComponent* InputComponent;
};
