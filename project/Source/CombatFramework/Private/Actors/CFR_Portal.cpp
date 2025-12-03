#include "Actors/CFR_Portal.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

ACFR_Portal::ACFR_Portal()
{
	PortalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PortalMesh"));
	RootComponent = PortalMesh;

	PortalArea = CreateDefaultSubobject<UBoxComponent>(TEXT("PortalArea"));
	PortalArea->SetupAttachment(RootComponent);
}

void ACFR_Portal::ActivatePortal()
{
	PortalMesh->SetVisibility(true, true);
}
