#include "GameFramework/CFR_ArenaGameMode.h"

#include "Kismet/GameplayStatics.h"

void ACFR_ArenaGameMode::StartPlay()
{
	Super::StartPlay();

	SpawnPlayer();
}
