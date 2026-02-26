#include "Subsystems/CFR_CinematicSubsystem.h"

#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"

#include "Actors/CFR_CinematicTrigger.h"

void UCFR_CinematicSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	FWorldDelegates::OnWorldCleanup.AddUObject(this, &UCFR_CinematicSubsystem::Cleanup);
}

void UCFR_CinematicSubsystem::RegisterTrigger(ACFR_CinematicTrigger* Trigger)
{
	if (Trigger && !RegisteredTriggers.Contains(Trigger))
	{
		RegisteredTriggers.Add(Trigger);
	}
}

void UCFR_CinematicSubsystem::StartCinematic(ACFR_CinematicTrigger* Trigger)
{
	if (bIsCinematicPlaying || !RegisteredTriggers.Contains(Trigger))
	{
		return;
	}

	CurrentTrigger = Trigger;

	ALevelSequenceActor* LevelSequenceActor;
	LevelSequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(
		GetWorld(),
		CurrentTrigger->CinematicSequence.Get(),
		FMovieSceneSequencePlaybackSettings(),
		LevelSequenceActor);

	if (!LevelSequencePlayer)
	{
		UE_LOG(LogTemp, Warning, TEXT("UCFR_CinematicSubsystem: Could not create LevelSequencePlayer."));

		bIsCinematicPlaying = false;
		CurrentTrigger = nullptr;
		OnCinematicEnded.Broadcast();
		return;
	}

	bIsCinematicPlaying = true;
	OnCinematicStarted.Broadcast();

	LevelSequencePlayer->OnFinished.AddDynamic(this, &UCFR_CinematicSubsystem::EndCinematic);
	LevelSequencePlayer->Play();
}

void UCFR_CinematicSubsystem::EndCinematic()
{
	if (!bIsCinematicPlaying)
	{
		return;
	}

	RegisteredTriggers.Remove(CurrentTrigger);
	bIsCinematicPlaying = false;
	CurrentTrigger = nullptr;

	OnCinematicEnded.Broadcast();
}

void UCFR_CinematicSubsystem::SkipCinematic()
{
	if (!bIsCinematicPlaying)
	{
		return;
	}

	if (LevelSequencePlayer)
	{
		LevelSequencePlayer->Stop();
	}

	EndCinematic();
}

void UCFR_CinematicSubsystem::Cleanup(UWorld* /*World*/, bool /*bSessionEnded*/, bool /*bCleanupResources*/)
{
	RegisteredTriggers.Empty();
}
