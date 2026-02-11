#pragma once

#include "CoreMinimal.h"

#include "CFR_CinematicTrigger.generated.h"

class UBillboardComponent;
class UBoxComponent;
class ULevelSequence;
class ULevelSequencePlayer;

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

	UPROPERTY(EditAnywhere)
	TObjectPtr<ULevelSequence> CinematicSequence;

	UPROPERTY(EditAnywhere)
	ECinematicTriggerType TriggerType = ECinematicTriggerType::Manual;

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void HandleOnFinished();

	void HandleOnSkipCutscene();

	ACFR_IGameMode* CurrentGameMode;

	TObjectPtr<ULevelSequencePlayer> LevelSequencePlayer;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* TriggerBox;

	UPROPERTY()
	TObjectPtr<UBillboardComponent> BillboardComponent;
};
