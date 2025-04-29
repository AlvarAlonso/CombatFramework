#include "Managers/CFR_SpawnerManager.h"

#include "Kismet/GameplayStatics.h"

#include "Characters/CFR_CharacterBase.h"
#include "Managers/CFR_SpawnPoint.h"
#include "GameFramework/CFR_IGameMode.h"

void UCFR_SpawnerManager::SpawnActors()
{
	const auto world = GetWorld();
	check(world);

	const auto cfrGameMode = Cast<ACFR_IGameMode>(UGameplayStatics::GetGameMode(world));
	if (!cfrGameMode)
	{
		UE_LOG(LogTemp, Error, TEXT("SpawnerManager must spawn with a valid CFR GameMode."));
		return;
	}

	const auto& pool = cfrGameMode->GetPoolManager();

	for (const auto& spawnPoint : SpawnPoints)
	{
		if (auto actor = pool.GetActor<ACFR_CharacterBase>())
		{
			spawnPoint->Spawn(actor);
		}
	}
}
