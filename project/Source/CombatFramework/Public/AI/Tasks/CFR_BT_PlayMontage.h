// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "CFR_BT_PlayMontage.generated.h"

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_BT_PlayMontage : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UCFR_BT_PlayMontage();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
protected:
	virtual EBTNodeResult::Type AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual FString GetStaticDescription() const override;

	UFUNCTION()
	void OnReceiveNotify(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload);
	void OnMontageEnded(UAnimMontage* Montage, bool bInterrupted);
	void CleanUp();
	void StopMontage();

protected:
	/** Animation asset to play. Note that it needs to match the skeleton of pawn this BT is controlling */
	UPROPERTY(Category = Node, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* MontageToPlay;

	/** if true the task will just trigger the animation and instantly finish. Fire and Forget. */
	UPROPERTY(Category = Node, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	bool bNonBlocking;

	UPROPERTY(Category = Node, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	FName NotifyEnd;

	UPROPERTY(Category = Node, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float BlendOutTime = 0.2f;

	TWeakObjectPtr<UBehaviorTreeComponent> CachedOwnerComp;
	TWeakObjectPtr<UAnimInstance> CachedAnimInstance;
};
