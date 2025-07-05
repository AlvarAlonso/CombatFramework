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

    FGameplayAbilitySpecHandle AbilitySpecHandle;
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

/** Delegate type used to broadcast InputAction events. Useful in cases like combo system related notify events, that rely on the next input pressed by a player. */
DECLARE_MULTICAST_DELEGATE_OneParam(FCFR_InputActionStartedDelegate, UInputAction*);
/** Delegate type used to broadcast completed InputAction events. */
DECLARE_MULTICAST_DELEGATE_OneParam(FCFR_InputActionCompletedDelegate, UInputAction*);

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

    // Add a stack of the tag only if it is not already added.
    UFUNCTION(BlueprintCallable, Category = "Abilities")
    void AddUniqueLooseGameplayTag(const FGameplayTag& GameplayTag);

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
    void BindDefaultAbilitiesInput(UEnhancedInputComponent* PlayerInputComponent);

    void InitializeAttributes();

    /* Input */
    UFUNCTION(BlueprintCallable, Category = "Input")
    void SetInputBinding(UInputAction* InputAction, FGameplayAbilitySpecHandle AbilitySpecHandle);
    /* ---------------------------- */

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

    /* Initializer gameplay effects. */
    UPROPERTY(EditDefaultsOnly, Category = "Attributes")
    TArray<TSubclassOf<UGameplayEffect>> StartupGameplayEffects;

    FCFR_InputActionStartedDelegate OnInputActionStarted;
    FCFR_InputActionCompletedDelegate OnInputActionCompleted;

protected:
    /* All abilities. */
    TArray<FGameplayAbilitySpecHandle> DefaultAbilityHandles;

    /* Abilities activated by an UInputAction. */
    TMap<UInputAction*, FCFR_AbilityInputBinding> AbilitiesBindingInfo;

    UPROPERTY(transient)
    UEnhancedInputComponent* InputComponent;
};
