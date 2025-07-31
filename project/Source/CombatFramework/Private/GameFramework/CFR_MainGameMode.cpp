
#include "GameFramework/CFR_MainGameMode.h"

#include "Kismet/GameplayStatics.h"

#include "Subsystems/CFR_ArenaSubsystem.h"

void ACFR_MainGameMode::StartPlay()
{
	Super::StartPlay();

	const auto SetPlayerSpawnToTrue = [this]()
		{
			bCanPlayerSpawn = true;
			const auto PlayerController = Cast<APlayerController>(UGameplayStatics::GetPlayerController(this, 0));
			RestartPlayer(PlayerController);
		};

	auto world = GetWorld();

	FTimerHandle SpawnPlayerTimerHandle;
	world->GetTimerManager().SetTimer(SpawnPlayerTimerHandle, SetPlayerSpawnToTrue, 2.0f, false);

	if (auto arenaManager = world->GetSubsystem<UCFR_ArenaSubsystem>())
	{
		arenaManager->OnArenaFinished.BindUObject(this, &ACFR_MainGameMode::PlayerWins);
	}
}

void ACFR_MainGameMode::RestartPlayer(AController* InNewPlayerController)
{
	Super::RestartPlayer(InNewPlayerController);

	const auto arenaSubsystem = GetWorld()->GetSubsystem<UCFR_ArenaSubsystem>();
	arenaSubsystem->StartArena();
}

bool ACFR_MainGameMode::GetCanPlayerSpawn() const
{
	return bCanPlayerSpawn;
}
