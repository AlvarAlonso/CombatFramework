// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AbilityTasks/CFR_PlayMontageAndWaitForEvent.h"

#include "AbilitySystemGlobals.h"
#include "GameFramework/Character.h"

#include "AbilitySystem/CFR_AbilitySystemComponent.h"

UCFR_PlayMontageAndWaitForEvent::UCFR_PlayMontageAndWaitForEvent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PlayRate = 1.0f;
	bStopWhenAbilityEnds = true;
}

void UCFR_PlayMontageAndWaitForEvent::Activate()
{
	Super::Activate();

	if (Ability == nullptr)
	{
		return;
	}

	bool bPlayedMontage = false;
	UCFR_AbilitySystemComponent* ASC = GetTargetASC();

	if (ASC)
	{
		const FGameplayAbilityActorInfo* ActorInfo = Ability->GetCurrentActorInfo();
		UAnimInstance* AnimInstance = ActorInfo->GetAnimInstance();
		if (AnimInstance != nullptr)
		{
			// Bind to event callback.
			EventHandle = ASC->AddGameplayEventTagContainerDelegate(EventTags, FGameplayEventTagMulticastDelegate::FDelegate::CreateUObject(this, &UCFR_PlayMontageAndWaitForEvent::OnGameplayEvent));
		
			if (ASC->PlayMontage(Ability, Ability->GetCurrentActivationInfo(), MontageToPlay, PlayRate, StartSection) > 0.0f)
			{
				// Playing a montage could potentially fire off a callback into game code which could kill this ability! Early out if we are pending kill.
				if (ShouldBroadcastAbilityTaskDelegates() == false)
				{
					return;
				}

				CancelledHandle = Ability->OnGameplayAbilityCancelled.AddUObject(this, &UCFR_PlayMontageAndWaitForEvent::OnAbilityCancelled);

				BlendingOutDelegate.BindUObject(this, &UCFR_PlayMontageAndWaitForEvent::OnMontageBlendingOut);
				AnimInstance->Montage_SetBlendingOutDelegate(BlendingOutDelegate, MontageToPlay);

				MontageEndedDelegate.BindUObject(this, &UCFR_PlayMontageAndWaitForEvent::OnMontageEnded);
				AnimInstance->Montage_SetEndDelegate(MontageEndedDelegate, MontageToPlay);

				ACharacter* Character = Cast<ACharacter>(GetAvatarActor());
				if (Character && (Character->GetLocalRole() == ROLE_Authority ||
					(Character->GetLocalRole() == ROLE_AutonomousProxy && Ability->GetNetExecutionPolicy() == EGameplayAbilityNetExecutionPolicy::LocalPredicted)))
				{
					Character->SetAnimRootMotionTranslationScale(AnimRootMotionTranslationScale);
				}

				bPlayedMontage = true;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("UCFR_PlayMontageAndWaitForEvent call to PlayMontage failed!"));
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("UCFR_PlayMontageAndWaitForEvent called on invalid AbilitySystemComponent"));
		}

		if (!bPlayedMontage)
		{
			UE_LOG(LogTemp, Warning, TEXT("URGX_AbilityTask_PlayMontageAndWaitForEvent called in Ability %s failed to play montage %s; Task Instance Name %s."), *Ability->GetName(), *GetNameSafe(MontageToPlay), *InstanceName.ToString());
			if (ShouldBroadcastAbilityTaskDelegates())
			{
				OnCancelled.Broadcast(FGameplayTag(), FGameplayEventData());
			}
		}
	}

	SetWaitingOnAvatar();
}

void UCFR_PlayMontageAndWaitForEvent::ExternalCancel()
{
	check(AbilitySystemComponent.Get());

	OnAbilityCancelled();

	Super::ExternalCancel();
}

FString UCFR_PlayMontageAndWaitForEvent::GetDebugString() const
{
	UAnimMontage* PlayingMontage = nullptr;
	if (Ability)
	{
		const FGameplayAbilityActorInfo* ActorInfo = Ability->GetCurrentActorInfo();
		UAnimInstance* AnimInstance = ActorInfo->GetAnimInstance();

		if (AnimInstance != nullptr) 
		{
			PlayingMontage = AnimInstance->Montage_IsActive(MontageToPlay) ? MontageToPlay : AnimInstance->GetCurrentActiveMontage();
		}
	}

	return FString::Printf(TEXT("PlayMontageAndWaitForEvent. MontageToPlay: %s  (Currently Playing): %s"), *GetNameSafe(MontageToPlay), *GetNameSafe(PlayingMontage));
}

void UCFR_PlayMontageAndWaitForEvent::OnDestroy(bool bAbilityEnded)
{
	// Note: Clearing montage end delegate isn't necessary since its not a multicast and will be cleared when the next montage plays.
	// (If we are destroyed, it will detect this and not do anything)

	// This delegate, however, should be cleared as it is a multicast
	if (Ability)
	{
		Ability->OnGameplayAbilityCancelled.Remove(CancelledHandle);
		if (bAbilityEnded && bStopWhenAbilityEnds)
		{
			StopPlayingMontage();
		}
	}

	UCFR_AbilitySystemComponent* CFR_AbilitySystemComponent = GetTargetASC();
	if (CFR_AbilitySystemComponent)
	{
		CFR_AbilitySystemComponent->RemoveGameplayEventTagContainerDelegate(EventTags, EventHandle);
	}

	Super::OnDestroy(bAbilityEnded);
}

UCFR_PlayMontageAndWaitForEvent* UCFR_PlayMontageAndWaitForEvent::PlayMontageAndWaitForEvent(UGameplayAbility* OwningAbility, FName TaskInstanceName, UAnimMontage* MontageToPlay, FGameplayTagContainer EventTags, float Rate, FName StartSection, bool bStopWhenAbilityEnds, float AnimRootMotionTranslationScale)
{
	UAbilitySystemGlobals::NonShipping_ApplyGlobalAbilityScaler_Rate(Rate);

	UCFR_PlayMontageAndWaitForEvent* MyObj = NewAbilityTask<UCFR_PlayMontageAndWaitForEvent>(OwningAbility, TaskInstanceName);
	MyObj->MontageToPlay = MontageToPlay;
	MyObj->EventTags = EventTags;
	MyObj->PlayRate = Rate;
	MyObj->StartSection = StartSection;
	MyObj->AnimRootMotionTranslationScale = AnimRootMotionTranslationScale;
	MyObj->bStopWhenAbilityEnds = bStopWhenAbilityEnds;

	return MyObj;
}

bool UCFR_PlayMontageAndWaitForEvent::StopPlayingMontage()
{
	const FGameplayAbilityActorInfo* ActorInfo = Ability->GetCurrentActorInfo();
	if (!ActorInfo)
	{
		return false;
	}

	UAnimInstance* AnimInstance = ActorInfo->GetAnimInstance();
	if (AnimInstance)
	{
		return false;
	}

	// Check if the montage is still playing.
	// The ability would have been interrupted, in which case we should automatically stop the montage.
	if (AbilitySystemComponent.Get() && Ability)
	{
		if (AbilitySystemComponent->GetAnimatingAbility() == Ability
			&& AbilitySystemComponent->GetCurrentMontage() == MontageToPlay)
		{
			// Unbind delegates so they don't get called as well.
			FAnimMontageInstance* MontageInstance = AnimInstance->GetActiveInstanceForMontage(MontageToPlay);
			if (MontageInstance)
			{
				MontageInstance->OnMontageBlendingOutStarted.Unbind();
				MontageInstance->OnMontageEnded.Unbind();
			}

			AbilitySystemComponent->CurrentMontageStop();
			return true;
		}
	}

	return false;
}

UCFR_AbilitySystemComponent* UCFR_PlayMontageAndWaitForEvent::GetTargetASC()
{
	return Cast<UCFR_AbilitySystemComponent>(AbilitySystemComponent);
}

void UCFR_PlayMontageAndWaitForEvent::OnMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted)
{
	if (Ability && Ability->GetCurrentMontage() == MontageToPlay && Montage == MontageToPlay)
	{
		AbilitySystemComponent->ClearAnimatingAbility(Ability);

		// Reset AnimRootMotionTranslationScale.
		ACharacter* Character = Cast<ACharacter>(GetAvatarActor());
		if (Character && (Character->GetLocalRole() == ROLE_Authority ||
			(Character->GetLocalRole() == ROLE_AutonomousProxy && Ability->GetNetExecutionPolicy() == EGameplayAbilityNetExecutionPolicy::LocalPredicted)))
		{
			Character->SetAnimRootMotionTranslationScale(1.0f);
		}
	}

	if (bInterrupted)
	{
		if (ShouldBroadcastAbilityTaskDelegates())
		{
			OnInterrupted.Broadcast(FGameplayTag(), FGameplayEventData());
		}
	}
	else
	{
		if (ShouldBroadcastAbilityTaskDelegates())
		{
			OnBlendOut.Broadcast(FGameplayTag(), FGameplayEventData());
		}
	}
}

void UCFR_PlayMontageAndWaitForEvent::OnAbilityCancelled()
{
	if (StopPlayingMontage())
	{
		// Let the BP handle the interrupt as well.
		if (ShouldBroadcastAbilityTaskDelegates())
		{
			OnCancelled.Broadcast(FGameplayTag(), FGameplayEventData());
		}
	}
}

void UCFR_PlayMontageAndWaitForEvent::OnMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	if (!bInterrupted)
	{
		if (ShouldBroadcastAbilityTaskDelegates())
		{
			OnCompleted.Broadcast(FGameplayTag(), FGameplayEventData());
		}
	}

	EndTask();
}

void UCFR_PlayMontageAndWaitForEvent::OnGameplayEvent(FGameplayTag EventTag, const FGameplayEventData* Payload)
{
	if (ShouldBroadcastAbilityTaskDelegates())
	{
		FGameplayEventData TempData = *Payload;
		TempData.EventTag = EventTag;

		OnEventReceived.Broadcast(EventTag, TempData);
	}
}
