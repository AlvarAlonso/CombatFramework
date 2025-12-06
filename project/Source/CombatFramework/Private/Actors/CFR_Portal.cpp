#include "Actors/CFR_Portal.h"

#include "Kismet/GameplayStatics.h"

#include "Characters/CFR_PlayerCharacter.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

ACFR_Portal::ACFR_Portal()
{
	PortalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PortalMesh"));
	RootComponent = PortalMesh;

	PortalArea = CreateDefaultSubobject<UBoxComponent>(TEXT("PortalArea"));
	PortalArea->SetupAttachment(RootComponent);
}

void ACFR_Portal::SetVisible()
{
	PortalMesh->SetVisibility(true, true);
	PortalArea->OnComponentBeginOverlap.AddDynamic(this, &ACFR_Portal::OnPortalOverlapped);
}

void ACFR_Portal::ActivatePortal()
{
	PendingLevelsToLoad--;

	if (PendingLevelsToLoad > 0)
	{
		return;
	}

	const auto player = Cast<ACFR_PlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	check(player);

	player->SetActorLocation(TargetPortal->GetActorLocation());

	const auto world = GetWorld();
	int32 UUIDcounter = 0;

	for (const auto levelToUnload : LevelsToUnload)
	{
		FLatentActionInfo latentActionInfo{};
		latentActionInfo.UUID = UUIDcounter++;
		latentActionInfo.CallbackTarget = this;

		UGameplayStatics::UnloadStreamLevelBySoftObjectPtr(world, levelToUnload, latentActionInfo, false);
	}
}

void ACFR_Portal::OnPortalOverlapped(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	const auto player = Cast<ACFR_PlayerCharacter>(OtherActor);
	if (!player)
	{
		return;
	}

	PendingLevelsToLoad = LevelsToLoad.Num();
	const auto world = GetWorld();
	int32 UUIDCounter = 0;

	for (const auto levelToLoad : LevelsToLoad)
	{
		if (auto streamingLevel = UGameplayStatics::GetStreamingLevel(world, levelToLoad.GetLongPackageFName()))
		{
			streamingLevel->OnLevelShown.AddDynamic(this, &ACFR_Portal::ActivatePortal);

			FLatentActionInfo latentActionInfo{};
			latentActionInfo.CallbackTarget = this;
			latentActionInfo.ExecutionFunction = FName("OnLevelLoaded");
			latentActionInfo.Linkage = 0;
			latentActionInfo.UUID = UUIDCounter++;

			UGameplayStatics::LoadStreamLevelBySoftObjectPtr(world, levelToLoad, true, false, latentActionInfo);
		}
	}
}
