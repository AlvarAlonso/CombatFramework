// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifies/AN_ConditionalJumpToSection.h"
#include "Characters/CFR_CharacterBase.h"

void UAN_ConditionalJumpToSection::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	auto* Owner = MeshComp->GetOwner();
	if (Owner)
	{
		const auto EvaluatorObject = Evaluator.GetDefaultObject();
		if (EvaluatorObject)
		{
			const bool Result = Evaluator.GetDefaultObject()->Evaluate_Implementation(Owner);
			if (Result)
			{
				ACFR_CharacterBase* Character = Cast<ACFR_CharacterBase>(MeshComp->GetOwner());
				Character->GetMesh()->GetAnimInstance()->Montage_JumpToSection(SectionName);
			}
		}
	}
}
