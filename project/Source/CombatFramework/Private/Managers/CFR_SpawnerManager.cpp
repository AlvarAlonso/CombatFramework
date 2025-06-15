#include "Managers/CFR_SpawnerManager.h"

#include "Kismet/GameplayStatics.h"

#include "Characters/CFR_CharacterBase.h"
#include "Managers/CFR_SpawnPoint.h"
#include "GameFramework/CFR_IGameMode.h"

void UCFR_SpawnerManager::Init()
{
	const auto world = GetWorld();
	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(world, ACFR_SpawnPoint::StaticClass(), actors);

	SpawnPoints.Reserve(actors.Num());

	for (auto actor : actors)
	{
		SpawnPoints.Add(Cast<ACFR_SpawnPoint>(actor));
	}
}

void UCFR_SpawnerManager::SpawnActors(TSubclassOf<ACFR_AICharacter> InActorTypeToSpawn, int InNumberActorsToSpawn)
{
	const auto world = GetWorld();
	check(world);

	const auto cfrGameMode = Cast<ACFR_IGameMode>(UGameplayStatics::GetGameMode(world));
	if (!cfrGameMode)
	{
		UE_LOG(LogTemp, Error, TEXT("SpawnerManager must spawn with a valid CFR GameMode."));
		return;
	}

	const auto poolManager = cfrGameMode->GetPoolManager();

	for (const auto& spawnPoint : SpawnPoints)
	{
		if (auto actor = Cast<ACFR_CharacterBase>(poolManager->GetActor(InActorTypeToSpawn)))
		{
			spawnPoint->Spawn(actor);
		}
	}
}
