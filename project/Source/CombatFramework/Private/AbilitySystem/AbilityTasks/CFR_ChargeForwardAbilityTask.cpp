// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AbilityTasks/CFR_ChargeForwardAbilityTask.h"
#include "Characters/CFR_CharacterBase.h"
#include "Components/CFR_HitboxComponent.h"
#include "Components/CFR_HitboxesManagerComponent.h"

UCFR_ChargeForwardAbilityTask::UCFR_ChargeForwardAbilityTask(const FObjectInitializer& ObjectInitializer)
{
	bTickingTask = true;
}

UCFR_ChargeForwardAbilityTask* UCFR_ChargeForwardAbilityTask::ChargeForwardAbilityTask(UGameplayAbility* OwningAbility, FName TaskInstanceName, float Duration, FGameplayTag HitboxTag)
{
	UCFR_ChargeForwardAbilityTask* Task = NewAbilityTask<UCFR_ChargeForwardAbilityTask>(OwningAbility, TaskInstanceName);
	Task->Duration = Duration;
	Task->HitboxTag = HitboxTag;

	return Task;
}

void UCFR_ChargeForwardAbilityTask::Activate()
{
	Super::Activate();

	if (ACFR_CharacterBase* Owner = Cast<ACFR_CharacterBase>(GetAvatarActor()))
	{
		if (UCFR_HitboxesManagerComponent* HitboxesManagerComp = Cast<UCFR_HitboxesManagerComponent>(Owner->GetComponentByClass(UCFR_HitboxesManagerComponent::StaticClass())))
		{
			if (UCFR_HitboxComponent* Hitbox = HitboxesManagerComp->GetHitboxByTag(HitboxTag))
			{
				Hitbox->OnHitboxOverlap.__Internal_AddDynamic(this, &UCFR_ChargeForwardAbilityTask::OnHitboxOverlap, "OnHitboxOverlap");
			}
		}
	}

	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle,
		this,
		&UCFR_ChargeForwardAbilityTask::OnChargeFinished,
		Duration,
		false);
}

void UCFR_ChargeForwardAbilityTask::TickTask(float DeltaTime)
{
	ACFR_CharacterBase* Owner = Cast<ACFR_CharacterBase>(GetAvatarActor());
	if (Owner == nullptr)
	{
		return;
	}

	APawn* Pawn = Owner->GetController()->GetPawn();
	if (Pawn == nullptr)
	{
		return;
	}

	Pawn->AddMovementInput(Owner->GetActorForwardVector());
}

void UCFR_ChargeForwardAbilityTask::OnHitboxOverlap(AActor* OverlappedActor)
{
	if (ACFR_CharacterBase* Owner = Cast<ACFR_CharacterBase>(GetAvatarActor()))
	{
		if (Owner->TargetActor == OverlappedActor)
		{
			EndTask();

			if (OnOverlapped.IsBound())
				OnOverlapped.Broadcast();
		}
	}
}

void UCFR_ChargeForwardAbilityTask::OnChargeFinished()
{
	EndTask();

	if (OnFinished.IsBound())
		OnFinished.Broadcast();

	return;
}
