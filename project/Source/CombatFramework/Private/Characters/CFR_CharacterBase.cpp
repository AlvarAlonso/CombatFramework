// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/CFR_CharacterBase.h"

#include "AbilitySystemComponent.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffectTypes.h"
#include "Kismet/KismetMathLibrary.h"

#include "AbilitySystem/CFR_AbilitySystemComponent.h"
#include "AbilitySystem/CFR_AttributeSet.h"
#include "AbilitySystem/CFR_EventDataPayloads.h"
#include "AbilitySystem/CFR_GameplayTags.h"
#include "Components/CFR_MovementAssistComponent.h"

ACFR_CharacterBase::ACFR_CharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	MovementAssistComponent = CreateDefaultSubobject<UCFR_MovementAssistComponent>("MovementAssistComponent");
}

UAbilitySystemComponent* ACFR_CharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

bool ACFR_CharacterBase::IsAlive() const
{
	return GetHealth() > 0.0f;
}

float ACFR_CharacterBase::GetHealth() const
{
	const auto AttrSet = GetAbilitySystemComponent()->GetSet<UCFR_AttributeSet>();
	check(AttrSet);

	return AttrSet->GetCurrentHealth();
}

float ACFR_CharacterBase::GetMaxHealth() const
{
	const auto AttrSet = GetAbilitySystemComponent()->GetSet<UCFR_AttributeSet>();
	check(AttrSet);

	return AttrSet->GetMaxHealth();
}

float ACFR_CharacterBase::GetDefaultGravityScale() const
{
	return GravityScale;
}

float ACFR_CharacterBase::GetDefaultMaxAcceleration() const
{
	return MaxAcceleration;
}

void ACFR_CharacterBase::PushCharacter(AActor* ActorInstigator, const UCFR_LaunchEventDataAsset* LaunchPayload)
{
	if (CanBeLaunched(ActorInstigator, LaunchPayload) == false) return;

	// Decompose payload
	const FVector ActorLocation = GetActorLocation();
	float VerticalForce = LaunchPayload->LaunchVerticalForce;
	const float HorizontalForce = LaunchPayload->LaunchHorizontalForce;
	const bool bOverrideXY = LaunchPayload->bOverrideHorizontal;
	const bool bOverrideZ = LaunchPayload->bOverrideVertical;

	FVector LaunchHorizontalDirection;

	// Get force horizontal direction depending on the instigator origin or if the actor applies a force to itself
	if (ActorInstigator && LaunchPayload->bInstigatorOrigin)
	{
		const FVector ForceOrigin = ActorInstigator->GetActorLocation();
		LaunchHorizontalDirection = ActorLocation - ForceOrigin;
		LaunchHorizontalDirection.Z = 0.0f;
		LaunchHorizontalDirection.Normalize();
	}
	else
	{
		LaunchHorizontalDirection = GetActorForwardVector();
	}

	if (bCanBeKnockup == false)
	{
		VerticalForce = 0.0f;
	}

	FVector LaunchForce = LaunchHorizontalDirection * HorizontalForce + FVector(0.0f, 0.0f, 1.0f) * VerticalForce;

	LaunchCharacter(LaunchForce, bOverrideXY, bOverrideZ);

	if (LaunchPayload->bKnockUp == true && bCanBeKnockup == true)
	{
		AbilitySystemComponent->AddLooseGameplayTag(FCFR_GameplayTags::Get().Status_KnockedUp);
	}
}

void ACFR_CharacterBase::HandleOnTakeDamage(const float Damage)
{
	if (OnDamageTakenDelegate.IsBound())
	{
		OnDamageTakenDelegate.Broadcast(Damage);
	}
}

void ACFR_CharacterBase::BeginPlay()
{
	Super::BeginPlay();

	UCharacterMovementComponent* CharacterMovementComponent = GetCharacterMovement();
	if (CharacterMovementComponent)
	{
		CharacterMovementComponent->MaxAcceleration = MaxAcceleration;
		CharacterMovementComponent->GravityScale = GravityScale;
	}
}

void ACFR_CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckKnockUpState();
}

void ACFR_CharacterBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	auto* CFR_ASC = Cast<UCFR_AbilitySystemComponent>(AbilitySystemComponent);

	if (CFR_ASC)
	{
		CFR_ASC->OnMeleeAbilityActivated.Remove(OnMeleeAbilityActivatedDelegateHandle);
		CFR_ASC->OnMeleeAbilityEnded.Remove(OnMeleeAbilityEndedDelegateHandle);
		CFR_ASC->OnAirAbilityActivated.Remove(OnAirAbilityActivatedDelegateHandle);
		CFR_ASC->OnAirAbilityEnded.Remove(OnAirAbilityEndedDelegateHandle);
	}

	Super::EndPlay(EndPlayReason);
}

void ACFR_CharacterBase::Falling()
{
	if (!AbilitySystemComponent->HasMatchingGameplayTag(FCFR_GameplayTags::Get().Status_OnAir))
	{
		AbilitySystemComponent->AddLooseGameplayTag(FCFR_GameplayTags::Get().Status_OnAir);
	}
}

void ACFR_CharacterBase::Landed(const FHitResult& Hit)
{
	AbilitySystemComponent->RemoveLooseGameplayTag(FCFR_GameplayTags::Get().Status_OnAir);
	AbilitySystemComponent->RemoveLooseGameplayTag(FCFR_GameplayTags::Get().Status_AirStable);
	AbilitySystemComponent->RemoveLooseGameplayTag(FCFR_GameplayTags::Get().Status_AirDashed);
}

bool ACFR_CharacterBase::CanBeLaunched(AActor* ActorInstigator, const UCFR_LaunchEventDataAsset* LaunchPayload)
{
	return true;
}

bool ACFR_CharacterBase::IsFallingDown()
{
	return GetCharacterMovement() && GetCharacterMovement()->IsFalling() && GetVelocity().Z < 0;
}

bool ACFR_CharacterBase::GetIsActive() const
{
	return bIsActive;
}

void ACFR_CharacterBase::Die()
{
	HandleStartDying();
}

void ACFR_CharacterBase::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	AbilitySystemComponent->GetOwnedGameplayTags(TagContainer);
}

bool ACFR_CharacterBase::HasMatchingGameplayTag(FGameplayTag TagToCheck) const
{
	return AbilitySystemComponent->HasMatchingGameplayTag(TagToCheck);
}

bool ACFR_CharacterBase::HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const
{
	return AbilitySystemComponent->HasAllMatchingGameplayTags(TagContainer);
}

bool ACFR_CharacterBase::HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const
{
	return AbilitySystemComponent->HasAnyMatchingGameplayTags(TagContainer);
}

void ACFR_CharacterBase::AddGameplayTag(const FGameplayTag& TagToAdd)
{
	AbilitySystemComponent->AddLooseGameplayTag(TagToAdd);
}

void ACFR_CharacterBase::RemoveGameplayTag(const FGameplayTag& TagToRemove, bool bCleanAll)
{
	if (bCleanAll)
	{
		const int32 TagCount = AbilitySystemComponent->GetTagCount(TagToRemove);
		AbilitySystemComponent->RemoveLooseGameplayTag(TagToRemove, TagCount);
	}
	else
	{
		AbilitySystemComponent->RemoveLooseGameplayTag(TagToRemove);
	}
}

void ACFR_CharacterBase::InitializeAbilitySystemComponentCallbacks()
{
	auto* CFR_ASC = Cast<UCFR_AbilitySystemComponent>(AbilitySystemComponent);
	check(CFR_ASC)

		if (CFR_ASC)
		{
			CFR_ASC->RegisterGameplayTagEvent(FCFR_GameplayTags::Get().Status_KnockedUp).
				AddUObject(this, &ACFR_CharacterBase::HandleKnockedUp);

			OnMeleeAbilityActivatedDelegateHandle = CFR_ASC->OnMeleeAbilityActivated.AddUObject(this, &ACFR_CharacterBase::HandleMeleeAbilityActivated);
			OnMeleeAbilityEndedDelegateHandle = CFR_ASC->OnMeleeAbilityEnded.AddUObject(this, &ACFR_CharacterBase::HandleMeleeAbilityEnded);
			OnAirAbilityActivatedDelegateHandle = CFR_ASC->OnAirAbilityActivated.AddUObject(this, &ACFR_CharacterBase::HandleAirAbilityActivated);
			OnAirAbilityEndedDelegateHandle = CFR_ASC->OnAirAbilityEnded.AddUObject(this, &ACFR_CharacterBase::HandleAirAbilityEnded);
		}
}

void ACFR_CharacterBase::HandleKnockedUp(const FGameplayTag CallbackTag, int32 NewCount)
{
	UE_LOG(LogTemp, Warning, TEXT("HANDLE KNOCKED UP"));
}

void ACFR_CharacterBase::HandleStartDying()
{
	StopAnimMontage();

	// TODO: Stop AI logic if the Actor is not a player.
	// TODO: Should death be an ability?
	if (PlayAnimMontage(DeathMontage) > 0.0f)
	{
		auto* AnimInstance = GetMesh()->GetAnimInstance();
		DeathMontageEndedDelegate.BindUObject(this, &ACFR_CharacterBase::OnDeathMontageEnded);
		AnimInstance->Montage_SetEndDelegate(DeathMontageEndedDelegate, DeathMontage);
	}
	else
	{
		HandleFinishDying();
	}
}

void ACFR_CharacterBase::OnDeathMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	HandleFinishDying();
}

void ACFR_CharacterBase::NotifyDeath()
{
	HandleFinishDying();
}

void ACFR_CharacterBase::HandleFinishDying()
{
	StopAnimMontage();
}

void ACFR_CharacterBase::HandleHealthChanged(const FOnAttributeChangeData& InData)
{
	BP_OnDamageTaken();
}

void ACFR_CharacterBase::CheckKnockUpState()
{
	if (AbilitySystemComponent->HasMatchingGameplayTag(FCFR_GameplayTags::Get().Status_KnockedUp) &&
		IsFallingDown())
	{
		AbilitySystemComponent->RemoveLooseGameplayTag(FCFR_GameplayTags::Get().Status_KnockedUp);

		UCharacterMovementComponent* CharacterMovementComponent = GetCharacterMovement();
		if (CharacterMovementComponent && !AbilitySystemComponent->HasMatchingGameplayTag(FCFR_GameplayTags::Get().Status_AirStable))
		{
			CharacterMovementComponent->GravityScale = 0.0f;

			// Reset gravity scale after a delay.
			FTimerDelegate TimerDelegate;
			FTimerHandle TimerHandle;
			TimerDelegate.BindUObject(this, &ACFR_CharacterBase::HandleKnockedUpEnded);
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, TimeGravityZeroAfterKnockedUp, false);
		}
	}
}

void ACFR_CharacterBase::HandleKnockedUpEnded()
{
	// We want to reset gravity scale only if gravity is not already being overriden by other effects.
	if (!AbilitySystemComponent->HasMatchingGameplayTag(FCFR_GameplayTags::Get().Status_AirStable))
	{
		UCharacterMovementComponent* CharacterMovementComponent = GetCharacterMovement();
		if (CharacterMovementComponent)
		{
			CharacterMovementComponent->MaxAcceleration = MaxAcceleration;
			CharacterMovementComponent->GravityScale = GravityScale;
		}
	}
}

void ACFR_CharacterBase::HandleMeleeAbilityActivated(UGameplayAbility* GameplayAbility)
{
}

void ACFR_CharacterBase::HandleMeleeAbilityEnded(UGameplayAbility* GameplayAbility)
{
}

void ACFR_CharacterBase::HandleAirAbilityActivated(UGameplayAbility* GameplayAbility)
{
	// Right now, only one air attack ability activation should be permitted. Air abilities should be blocked against this tag.
	if (!AbilitySystemComponent->HasMatchingGameplayTag(FCFR_GameplayTags::Get().Status_AirStable))
	{
		AbilitySystemComponent->AddLooseGameplayTag(FCFR_GameplayTags::Get().Status_AirStable);
	}

	FGameplayTagContainer TagContainer;
	TagContainer.AddTag(FCFR_GameplayTags::Get().Ability_Jump);
	AbilitySystemComponent->CancelAbilities(&TagContainer);
	LaunchCharacter(FVector(0.0f, 0.0f, -1.0f), true, true);
	GetCharacterMovement()->GravityScale = 0.0f;
}

void ACFR_CharacterBase::HandleAirAbilityEnded(UGameplayAbility* GameplayAbility)
{
	GetCharacterMovement()->GravityScale = GravityScale;
}
