#pragma once

#include "CoreMinimal.h"

#include "CFR_CinematicManager.generated.h"

class ULevelSequencePlayer;

class ACFR_CinematicTrigger;

DECLARE_MULTICAST_DELEGATE(FOnCinematicStarted);
DECLARE_MULTICAST_DELEGATE(FOnCinematicEnded);

UCLASS()
class COMBATFRAMEWORK_API UCFR_CinematicManager : public UObject
{
	GENERATED_BODY()

public:
	void RegisterTrigger(ACFR_CinematicTrigger* Trigger);
	void StartCinematic(ACFR_CinematicTrigger* Trigger);

	UFUNCTION()
	void EndCinematic();
	void SkipCinematic();

	const TArray<TObjectPtr<ACFR_CinematicTrigger>>& GetRegisteredTriggers() const { return RegisteredTriggers; }
	bool IsCinematicPlaying() const { return bIsCinematicPlaying; }

	FOnCinematicStarted OnCinematicStarted;
	FOnCinematicEnded OnCinematicEnded;

private:
	UPROPERTY()
	TArray<TObjectPtr<ACFR_CinematicTrigger>> RegisteredTriggers;

	TObjectPtr<ULevelSequencePlayer> LevelSequencePlayer;

	ACFR_CinematicTrigger* CurrentTrigger = nullptr;

	bool bIsCinematicPlaying = false;
};
