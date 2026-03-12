
#include "AbilitySystem/GameplayAbilities/CFR_GA_Spear.h"

#include "Kismet/GameplayStatics.h"

#include "Actors/CFR_Spear.h"
#include "Characters/CFR_AICharacter.h"
#include "Components/CFR_TargettingComponent.h"

void UCFR_GA_Spear::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		constexpr bool bReplicateEndAbility = true;
		constexpr bool bWasCancelled = true;
		EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
	}

	CastSpears(ActorInfo->AvatarActor.Get());

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}

void UCFR_GA_Spear::CastSpears(AActor* InCasterActor)
{
	check(InCasterActor);

	const auto casterLocation = InCasterActor->GetActorLocation();
	const auto casterRotation = InCasterActor->GetActorRotation();
	const auto casterRight = InCasterActor->GetActorRightVector();
	const auto casterForward = InCasterActor->GetActorForwardVector();

	for (int i = 0; i < MaxNumberOfSpears; i++)
	{
		const auto spearAngle = (SpearAngle / MaxNumberOfSpears) * i;
		const auto spearOffsetRotation = casterRight.RotateAngleAxis(spearAngle, casterForward);

		const auto spawnLocation = casterLocation + spearOffsetRotation * DistanceFromCaster;

		if (auto spear = GetWorld()->SpawnActor<ACFR_Spear>(SpearClass, spawnLocation, casterRotation))
		{
			spear->DistanceFromCaster = DistanceFromCaster;
			spear->Angle = spearAngle;
			spear->Instigator = InCasterActor;

			if (const auto teamAgent = Cast<IGenericTeamAgentInterface>(InCasterActor))
			{
				spear->SetGenericTeamId(teamAgent->GetGenericTeamId());
			}

			Spears.Add(spear);
		}
	}

	ACFR_CharacterBase* targetActor = nullptr;

	if (InCasterActor->FindComponentByClass<UCFR_TargettingComponent>()->GetCurrentTarget().IsValid())
	{
		targetActor = InCasterActor->FindComponentByClass<UCFR_TargettingComponent>()->GetCurrentTarget().Get();
	}
	else
	{
		TArray<AActor*> foundTargets;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACFR_AICharacter::StaticClass(), foundTargets);

		float closestEnemyDistance = INFINITY;

		for (const auto& target : foundTargets)
		{
			const auto aiTarget = Cast<ACFR_AICharacter>(target);

			if (!aiTarget->GetIsActive())
			{
				continue;
			}

			if (aiTarget->GetAbilitySystemComponent()->HasMatchingGameplayTag(FGameplayTag::RequestGameplayTag(FName("Status.Dead"))))
			{
				continue;
			}

			const auto distance = FVector::Distance(InCasterActor->GetActorLocation(), target->GetActorLocation());
			if (distance < closestEnemyDistance)
			{
				closestEnemyDistance = distance;
				targetActor = aiTarget;
			}
		}
	}

	for (const auto& spear : Spears)
	{
		spear->LaunchSpear(targetActor);
	}

	Spears.Empty();
}
