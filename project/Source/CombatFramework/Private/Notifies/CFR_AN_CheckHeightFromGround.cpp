// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifies/CFR_AN_CheckHeightFromGround.h"

#include "AbilitySystem/CFR_GameplayTags.h"

#include "Characters/CFR_CharacterBase.h"
#include "Kismet/KismetSystemLibrary.h"
#include "AbilitySystemComponent.h"

void UCFR_AN_CheckHeightFromGround::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	const AActor* Owner = MeshComp->GetOwner();

	const ACFR_CharacterBase* CharacterBase = Cast<ACFR_CharacterBase>(Owner);
	if (CharacterBase)
	{
		const FVector TraceStart = CharacterBase->GetActorLocation();
		const FVector TraceEnd = TraceStart - FVector(0.0f, 0.0f, Distance);

		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
		ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldStatic));

		const TArray<AActor*> ActorsToIgnore;
		FHitResult OutHit;
		UWorld* World = Owner->GetWorld();

		bool bResult = UKismetSystemLibrary::LineTraceSingleForObjects(
			World, TraceStart, TraceEnd, ObjectTypes, false, ActorsToIgnore, 
			EDrawDebugTrace::ForDuration, OutHit, true, FLinearColor::Red, FLinearColor::Green, 3.0f);

		if (bResult == true)
		{
			UAbilitySystemComponent* ACS = Owner->FindComponentByClass<UAbilitySystemComponent>();
			if (ACS)
			{
				FGameplayEventData EventData;
				// TODO: Maybe this Notify should only check distance to ground and send this information. Nothing else.
				// TODO: Everything that can be in the gameplay abilities should be outside montages. 
				//	Montages should only send events and ability implementations answer to those events.
				ACS->HandleGameplayEvent(FCFR_GameplayTags::Get().GameplayEvent_GoingToLand, &EventData);
			}
		}
	}
}
