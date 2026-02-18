#include "Actors/CFR_CinematicManager.h"

#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"

#include "Actors/CFR_CinematicTrigger.h"

void UCFR_CinematicManager::RegisterTrigger(ACFR_CinematicTrigger* Trigger)
{
	if (Trigger && !RegisteredTriggers.Contains(Trigger))
	{
		RegisteredTriggers.Add(Trigger);
	}
}

void UCFR_CinematicManager::StartCinematic(ACFR_CinematicTrigger* Trigger)
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
		UE_LOG(LogTemp, Warning, TEXT("UCFR_CinematicManager: Could not create LevelSequencePlayer."));

		bIsCinematicPlaying = false;
		CurrentTrigger = nullptr;
		OnCinematicEnded.Broadcast();
		return;
	}

	bIsCinematicPlaying = true;
	OnCinematicStarted.Broadcast();

	LevelSequencePlayer->OnFinished.AddDynamic(this, &UCFR_CinematicManager::EndCinematic);
	LevelSequencePlayer->Play();
}

void UCFR_CinematicManager::EndCinematic()
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

void UCFR_CinematicManager::SkipCinematic()
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
