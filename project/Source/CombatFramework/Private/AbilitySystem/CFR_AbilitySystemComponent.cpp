// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/CFR_AbilitySystemComponent.h"

#include "AbilitySystem/CFR_GameplayTags.h"
#include "Characters/CFR_CharacterBase.h"

#include "EnhancedInputComponent.h"
#include "GameFramework/PlayerState.h"
#include "GameFramework/PlayerController.h"

UCFR_AbilitySystemComponent::UCFR_AbilitySystemComponent()
{
	AbilityActivatedCallbacks.AddUObject(this, &UCFR_AbilitySystemComponent::HandleAbilityActivatedCallbacks);
	AbilityEndedCallbacks.AddUObject(this, &UCFR_AbilitySystemComponent::HandleAbilityEndedCallbacks);
}

FGameplayAbilitySpecHandle UCFR_AbilitySystemComponent::GrantAbilityOfType(TSubclassOf<UGameplayAbility> AbilityType, bool bRemoveAfterActivation)
{
	FGameplayAbilitySpecHandle AbilitySpecHandle;
	if (AbilityType)
	{
		FGameplayAbilitySpec AbilitySpec(AbilityType);
		AbilitySpec.RemoveAfterActivation = bRemoveAfterActivation;

		AbilitySpecHandle = GiveAbility(AbilitySpec);
	}

	return AbilitySpecHandle;
}

void UCFR_AbilitySystemComponent::GrantDefaultAbilities()
{
	// Remove current abilities.
	for (FGameplayAbilitySpecHandle AbilitySpecHandle : DefaultAbilityHandles)
	{
		SetRemoveAbilityOnEnd(AbilitySpecHandle);
	}
	DefaultAbilityHandles.Empty();

	// Grant default abilities.
	if (IsOwnerActorAuthoritative())
	{
		DefaultAbilityHandles.Reserve(DefaultAbilitiesInitData.Num());
		for (FCFR_AbilityInitData& AbilityInitData : DefaultAbilitiesInitData)
		{
			UClass* AbilityClass = AbilityInitData.Ability;
			if (AbilityClass)
			{				
				float CharacterLevel = 1.0f;
				if (const auto AvatarActor = Cast<ACFR_CharacterBase>(GetAvatarActor()))
				{
					CharacterLevel = AvatarActor->GetCharacterLevel();
				}

				FGameplayAbilitySpec AbilitySpec(AbilityClass, CharacterLevel);
				FGameplayAbilitySpecHandle AbilitySpecHandle = GiveAbility(AbilitySpec);
				DefaultAbilityHandles.Add(AbilitySpecHandle);

				/* Store handle to bind inputs later. */
				AbilityInitData.AbilitySpecHandle = AbilitySpecHandle;
			}
		}

		UE_LOG(LogTemp, Display, TEXT("Default gameplay abilities granted."));
	}
}

void UCFR_AbilitySystemComponent::BindDefaultAbilitiesInput(UEnhancedInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	InputComponent = PlayerInputComponent;

	for (FCFR_AbilityInitData& AbilityInitData : DefaultAbilitiesInitData)
	{
		if (AbilityInitData.InputAction)
		{
			UE_LOG(LogTemp, Display, TEXT("Setting Input Binding for %s."), *AbilityInitData.InputAction->GetFName().ToString());
			SetInputBinding(AbilityInitData.InputAction, AbilityInitData.AbilitySpecHandle);
		}
	}
}

void UCFR_AbilitySystemComponent::InitializeAttributes()
{
	// Apply effects, such as initializing the base attributes.
	for (TSubclassOf<UGameplayEffect>& GameplayEffect : StartupGameplayEffects)
	{
		FGameplayEffectContextHandle EffectContext = MakeEffectContext();
		EffectContext.AddSourceObject(this);

		float CharacterLevel = 1.0f;
		if (const auto AvatarActor = Cast<ACFR_CharacterBase>(GetAvatarActor()))
		{
			CharacterLevel = AvatarActor->GetCharacterLevel();
		}

		FGameplayEffectSpecHandle NewHandle = MakeOutgoingSpec(GameplayEffect, CharacterLevel, EffectContext);
		if (NewHandle.IsValid())
		{
			FActiveGameplayEffectHandle ActivateEffectHandle = ApplyGameplayEffectSpecToTarget(*NewHandle.Data.Get(), this);
		}
	}
}

void UCFR_AbilitySystemComponent::AddUniqueLooseGameplayTag(const FGameplayTag& GameplayTag)
{
	if (!HasMatchingGameplayTag(GameplayTag))
	{
		AddLooseGameplayTag(GameplayTag);
	}
}

void UCFR_AbilitySystemComponent::K2_AddLooseGameplayTag(const FGameplayTag& GameplayTag, int32 Count)
{
	AddLooseGameplayTag(GameplayTag, Count);
}

void UCFR_AbilitySystemComponent::K2_AddLooseGameplayTags(const FGameplayTagContainer& GameplayTags, int32 Count)
{
	AddLooseGameplayTags(GameplayTags, Count);
}

void UCFR_AbilitySystemComponent::K2_RemoveLooseGameplayTag(const FGameplayTag& GameplayTag, int32 Count)
{
	RemoveLooseGameplayTag(GameplayTag, Count);
}

void UCFR_AbilitySystemComponent::K2_RemoveLooseGameplayTags(const FGameplayTagContainer& GameplayTags, int32 Count)
{
	RemoveLooseGameplayTags(GameplayTags, Count);
}

namespace EnhancedInputAbilitySystem_Impl
{
	constexpr int32 InvalidInputID = 0;
	int32 IncrementingInputID = InvalidInputID;

	static int32 GetNextInputID()
	{
		return ++IncrementingInputID;
	}
}

void UCFR_AbilitySystemComponent::OnUnregister()
{
	Super::OnUnregister();

	AbilityActivatedCallbacks.RemoveAll(this);
	AbilityEndedCallbacks.RemoveAll(this);
}

void UCFR_AbilitySystemComponent::SetInputBinding(UInputAction* InputAction, FGameplayAbilitySpecHandle AbilitySpecHandle)
{
	check(InputAction);

	using namespace EnhancedInputAbilitySystem_Impl;

	FGameplayAbilitySpec* AbilityToBind = FindAbilitySpecFromHandle(AbilitySpecHandle);
	if (!AbilityToBind) 
	{
		UE_LOG(LogTemp, Warning, TEXT("No ability to bind to."));
		return;
	}
	
	FCFR_AbilityInputBinding* AbilityInputBinding = AbilitiesBindingInfo.Find(InputAction);
	if (AbilityInputBinding)
	{
		/* If this InputID is already bound, invalidate the bound ability. */
		FGameplayAbilitySpec* BoundAbility = FindAbilitySpecFromHandle(AbilityInputBinding->AbilitySpecHandle);
		if (BoundAbility && BoundAbility->InputID == AbilityInputBinding->InputID)
		{
			BoundAbility->InputID = InvalidInputID;
		}
	}
	else
	{
		AbilityInputBinding = &AbilitiesBindingInfo.Add(InputAction);
		AbilityInputBinding->InputID = GetNextInputID();
	}

	if (AbilityToBind)
	{
		AbilityToBind->InputID = AbilityInputBinding->InputID;
	}

	AbilityInputBinding->AbilitySpecHandle = AbilitySpecHandle;
	TryBindAbilityInput(InputAction, *AbilityInputBinding);
}

void UCFR_AbilitySystemComponent::TryBindAbilityInput(UInputAction* InputAction, FCFR_AbilityInputBinding& AbilityInputBinding)
{
	UE_LOG(LogTemp, Display, TEXT("TryBindingAbilityInput: %s"), *InputAction->GetFName().ToString());

	if (InputComponent)
	{
		if (AbilityInputBinding.OnPressedHandle == 0)
		{
			AbilityInputBinding.OnPressedHandle = InputComponent->BindAction(InputAction, ETriggerEvent::Triggered, this, &UCFR_AbilitySystemComponent::OnAbilityInputStarted, InputAction).GetHandle();
		}

		if (AbilityInputBinding.OnReleasedHandle == 0)
		{
			AbilityInputBinding.OnReleasedHandle = InputComponent->BindAction(InputAction, ETriggerEvent::Completed, this, &UCFR_AbilitySystemComponent::OnAbilityInputCompleted, InputAction).GetHandle();
		}
	}
}

void UCFR_AbilitySystemComponent::OnAbilityInputStarted(UInputAction* InputAction)
{
	UE_LOG(LogTemp, Display, TEXT("OnAbilityInputStarted"), *InputAction->GetFName().ToString());

	if (OnInputActionStarted.IsBound())
	{
		OnInputActionStarted.Broadcast(InputAction);
	}

	using namespace EnhancedInputAbilitySystem_Impl;

	FCFR_AbilityInputBinding* InputBinding = AbilitiesBindingInfo.Find(InputAction);
	if (InputBinding && ensure(InputBinding->InputID != InvalidInputID))
	{
		AbilityLocalInputPressed(InputBinding->InputID);
	}
}

void UCFR_AbilitySystemComponent::OnAbilityInputCompleted(UInputAction* InputAction)
{
	UE_LOG(LogTemp, Display, TEXT("OnAbilityInputCompleted"), *InputAction->GetFName().ToString());

	if (OnInputActionCompleted.IsBound())
	{
		OnInputActionCompleted.Broadcast(InputAction);
	}

	using namespace EnhancedInputAbilitySystem_Impl;

	FCFR_AbilityInputBinding* InputBinding = AbilitiesBindingInfo.Find(InputAction);
	if (InputBinding && ensure(InputBinding->InputID != InvalidInputID))
	{
		AbilityLocalInputReleased(InputBinding->InputID);
	}
}

void UCFR_AbilitySystemComponent::RemoveInputBinding(UInputAction* InputAction)
{
	if (FCFR_AbilityInputBinding* InputBinding = AbilitiesBindingInfo.Find(InputAction))
	{
		if (InputComponent)
		{
			InputComponent->RemoveBindingByHandle(InputBinding->OnPressedHandle);
			InputComponent->RemoveBindingByHandle(InputBinding->OnReleasedHandle);
		}

		using namespace EnhancedInputAbilitySystem_Impl;

		FGameplayAbilitySpec* AbilitySpec = FindAbilitySpecFromHandle(InputBinding->AbilitySpecHandle);
		if (AbilitySpec && AbilitySpec->InputID == InputBinding->InputID)
		{
			AbilitySpec->InputID = InvalidInputID;
		}

		AbilitiesBindingInfo.Remove(InputAction);
	}
}

void UCFR_AbilitySystemComponent::HandleAbilityActivatedCallbacks(UGameplayAbility* GameplayAbility)
{
	const auto Tags = GameplayAbility->GetAssetTags();
	if (Tags.HasTag(FCFR_GameplayTags::Get().Ability_Melee))
	{
		if (OnMeleeAbilityActivated.IsBound())
		{
			OnMeleeAbilityActivated.Broadcast(GameplayAbility);
		}
	}

	if (Tags.HasTag(FCFR_GameplayTags::Get().Ability_Air))
	{
		if (OnAirAbilityActivated.IsBound())
		{
			OnAirAbilityActivated.Broadcast(GameplayAbility);
		}
	}
}

void UCFR_AbilitySystemComponent::HandleAbilityEndedCallbacks(UGameplayAbility* GameplayAbility)
{
	const auto Tags = GameplayAbility->GetAssetTags();
	if (Tags.HasTag(FCFR_GameplayTags::Get().Ability_Melee))
	{
		if (OnMeleeAbilityEnded.IsBound())
		{
			OnMeleeAbilityEnded.Broadcast(GameplayAbility);
		}
	}

	if (Tags.HasTag(FCFR_GameplayTags::Get().Ability_Air))
	{
		if (OnAirAbilityEnded.IsBound())
		{
			OnAirAbilityEnded.Broadcast(GameplayAbility);
		}
	}
}
