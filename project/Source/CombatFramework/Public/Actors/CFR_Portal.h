#pragma once

#include "CFR_Portal.generated.h"

class UBoxComponent;

UCLASS(Blueprintable)
class COMBATFRAMEWORK_API ACFR_Portal : public AActor
{
	GENERATED_BODY()

public:
	ACFR_Portal();

	//UFUNCTION(BlueprintCallable, Category = "Portal")
	void ActivatePortal();

	//UFUNCTION(BlueprintCallable, Category = "Portal")
	//void DeactivatePortal();

	//UFUNCTION(BlueprintImplementableEvent, Category = "Portal")
	//void OnPortalActivated();

	//UFUNCTION(BlueprintImplementableEvent, Category = "Portal")
	//void OnPortalDeactivated();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Portal")
	TObjectPtr<UStaticMeshComponent> PortalMesh{ nullptr };

	UPROPERTY(EditDefaultsOnly, Category = "Portal")
	TObjectPtr<UBoxComponent> PortalArea{ nullptr };
};
