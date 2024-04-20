
#include "GameFramework/CFR_MainGameMode.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void ACFR_MainGameMode::StartPlay()
{
	Super::StartPlay();

	const auto SetPlayerSpawnToTrue = [this]()
		{
			bCanPlayerSpawn = true;
			const auto PlayerController = Cast<APlayerController>(UGameplayStatics::GetPlayerController(this, 0));
			RestartPlayer(PlayerController);
		};

	FTimerHandle SpawnPlayerTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(SpawnPlayerTimerHandle, SetPlayerSpawnToTrue, 2.0f, false);
}

bool ACFR_MainGameMode::GetCanPlayerSpawn() const
{
	return bCanPlayerSpawn;
}
