// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/QueryContext/CFR_EnvQueryItemType_Actor.h"

#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "EnvironmentQuery/EnvQueryTypes.h"

#include "AI/CFR_AIController.h"

void UCFR_EnvQueryItemType_Actor::SetContextHelper(FEnvQueryContextData& ContextData, const AActor* SingleActor)
{
	ContextData.ValueType = UCFR_EnvQueryItemType_Actor::StaticClass();
	ContextData.NumValues = 1;
	ContextData.RawData.SetNumUninitialized(sizeof(FWeakObjectPtr));

	UCFR_EnvQueryItemType_Actor::SetValue(ContextData.RawData.GetData(), SingleActor);
}

FVector UCFR_EnvQueryItemType_Actor::GetItemLocation(const uint8* RawData) const
{
	if (AActor* MyActor = UCFR_EnvQueryItemType_Actor::GetValue(RawData))
	{
		FHitResult result;
		FVector location = MyActor->GetActorLocation();
		FVector endLocation = MyActor->GetActorLocation(); endLocation.Z = -100.f;
		if (MyActor->GetWorld()->LineTraceSingleByChannel(result, location, endLocation, ECollisionChannel::ECC_GameTraceChannel7))
		{
			location.Z = result.ImpactPoint.Z;
		}

		DrawDebugCircle(MyActor->GetWorld(), location, 100.f, 16, FColor::Red);
		return location;
	}

	return FAISystem::InvalidLocation;
}

void UCFR_TargetQueryContext::ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const
{
	Super::ProvideContext(QueryInstance, ContextData);

	if (ACFR_AIController* controller = Cast<ACFR_AIController>((Cast<AActor>((QueryInstance.Owner).Get())->GetInstigatorController())))
	{
		if (AActor* Target = Cast<AActor>(controller->BlackboardComponent->GetValue<UBlackboardKeyType_Object>(controller->TargetKeyId)))
		{
			UCFR_EnvQueryItemType_Actor::SetContextHelper(ContextData, Target);
		}
	}
}
