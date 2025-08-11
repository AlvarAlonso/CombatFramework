// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Tasks/CFR_BT_PlayMontage.h"
#include "AIController.h"
#include "GameFramework/Character.h"

UCFR_BT_PlayMontage::UCFR_BT_PlayMontage()
{
	// instantiating to be able to use Timers
	bCreateNodeInstance = true;
	bNonBlocking = false;
}

EBTNodeResult::Type UCFR_BT_PlayMontage::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* const MyController = OwnerComp.GetAIOwner();

	EBTNodeResult::Type Result = EBTNodeResult::Failed;

	if (MontageToPlay && MyController && MyController->GetPawn())
	{
		USkeletalMeshComponent* SkelMesh = nullptr;
		ACharacter* const MyCharacter = Cast<ACharacter>(MyController->GetPawn());
		if (MyCharacter)
		{
			SkelMesh = MyCharacter->GetMesh();
		}
		else
		{
			SkelMesh = MyController->GetPawn()->FindComponentByClass<USkeletalMeshComponent>();
		}

		if (SkelMesh != nullptr)
		{
			if (UAnimInstance* AnimInstance = SkelMesh->GetAnimInstance()) {

				AnimInstance->Montage_Play(MontageToPlay);

				if (bNonBlocking)
				{
					// we're done here, report success so that BT can pick next task
					Result = EBTNodeResult::Succeeded;
				}
				else
				{
					CachedAnimInstance = AnimInstance;
					CachedOwnerComp = &OwnerComp;
					FOnMontageEnded MontageEndedDelegate = FOnMontageEnded::CreateUObject(this, &UCFR_BT_PlayMontage::OnMontageEnded);
					AnimInstance->Montage_SetEndDelegate(MontageEndedDelegate);

					if (!NotifyEnd.IsNone()) {
						AnimInstance->OnPlayMontageNotifyBegin.AddUniqueDynamic(this, &UCFR_BT_PlayMontage::OnReceiveNotify);
					}

					Result = EBTNodeResult::InProgress;
				}
			}

		}
	}

	return Result;
}

EBTNodeResult::Type UCFR_BT_PlayMontage::AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	CleanUp();
	StopMontage();
	return EBTNodeResult::Aborted;
}

FString UCFR_BT_PlayMontage::GetStaticDescription() const
{
	return FString::Printf(TEXT("%s: '%s'"), *Super::GetStaticDescription(), *GetNameSafe(MontageToPlay)
		, bNonBlocking ? TEXT(", non-blocking") : TEXT("blocking"));
}

void UCFR_BT_PlayMontage::OnReceiveNotify(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload)
{
	if (NotifyName == NotifyEnd) {
		CleanUp();
		StopMontage();
		if (CachedOwnerComp.IsValid()) {
			FinishLatentTask(*CachedOwnerComp.Get(), EBTNodeResult::Succeeded);
		}
	}
}

void UCFR_BT_PlayMontage::OnMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	EBTNodeResult::Type Result = EBTNodeResult::Succeeded;
	if (bInterrupted) 
	{
		Result = EBTNodeResult::Failed;
	}

	CleanUp();

	if (CachedOwnerComp.IsValid()) 
	{
		FinishLatentTask(*CachedOwnerComp.Get(), Result);
	}
}

void UCFR_BT_PlayMontage::CleanUp()
{
	if (CachedAnimInstance.IsValid()) 
	{
		CachedAnimInstance->OnPlayMontageNotifyBegin.RemoveDynamic(this, &UCFR_BT_PlayMontage::OnReceiveNotify);
		if (FAnimMontageInstance* CurrentInstance = CachedAnimInstance->GetActiveInstanceForMontage(MontageToPlay)) {
			CurrentInstance->OnMontageEnded.Unbind();
		}
	}
}

void UCFR_BT_PlayMontage::StopMontage()
{
	if (CachedAnimInstance.IsValid()) 
	{
		CachedAnimInstance->Montage_Stop(BlendOutTime, MontageToPlay);
	}
}
