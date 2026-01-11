#pragma once

#include "CoreMinimal.h"

#include "CFR_CinematicTrigger.generated.h"

class ACFR_IGameMode;

UENUM(BlueprintType)
enum class ECinematicTriggerType : uint8
{
	BeginPlay UMETA(DisplayName = "Begin Play"),
	Overlap   UMETA(DisplayName = "Trigger"),
	Manual    UMETA(DisplayName = "Manual"),
};

UCLASS()
class COMBATFRAMEWORK_API ACFR_CinematicTrigger : public AActor
{
	GENERATED_BODY()

public:
	ACFR_CinematicTrigger();

	UFUNCTION(BlueprintCallable)
	void TriggerCinematic();

	UFUNCTION()
	void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

	UPROPERTY(EditAnywhere, Category = "Cinematic")
	TObjectPtr<class ULevelSequence> CinematicSequence;

	UPROPERTY(EditAnywhere, Category = "Cinematic")
	ECinematicTriggerType TriggerType = ECinematicTriggerType::Manual;

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void HandleOnFinished();

	void HandleOnSkipCutscene();

	ACFR_IGameMode* CurrentGameMode;

	TObjectPtr<class ULevelSequencePlayer> LevelSequencePlayer;

	UPROPERTY(VisibleAnywhere, Category = "Cinematic")
	class UBoxComponent* TriggerBox;
};
