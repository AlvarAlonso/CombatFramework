#pragma once

#include "CFR_Portal.generated.h"

class UBoxComponent;
class UNiagaraComponent;

DECLARE_DELEGATE(FOnPlayerTeleported);

UCLASS(Blueprintable)
class COMBATFRAMEWORK_API ACFR_Portal : public AActor
{
	GENERATED_BODY()

public:
	ACFR_Portal();

	void SetVisible();

	FOnPlayerTeleported OnPlayerTeleported;

private:
	UFUNCTION()
	void ActivatePortal();

	UFUNCTION()
	void OnPortalOverlapped(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere, Category = "Portal")
	TArray<TSoftObjectPtr<UWorld>> LevelsToLoad;

	UPROPERTY(EditAnywhere, Category = "Portal")
	TArray<TSoftObjectPtr<UWorld>> LevelsToUnload;

	UPROPERTY(EditAnywhere, Category = "Portal")
	TSoftObjectPtr<ACFR_Portal> TargetPortal;

	UPROPERTY(EditDefaultsOnly, Category = "Portal")
	TObjectPtr<UBoxComponent> PortalArea{ nullptr };

	UPROPERTY(EditDefaultsOnly, Category = "Portal")
	TObjectPtr<UNiagaraComponent> NiagaraComponent{ nullptr };

	uint32 PendingLevelsToLoad{ 0 };
};
