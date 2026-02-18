#include "Actors/CFR_CinematicTrigger.h"

#include "Components/BillboardComponent.h"
#include "Components/BoxComponent.h"

#include "Actors/CFR_CinematicManager.h"
#include "GameFramework/CFR_IGameMode.h"

ACFR_CinematicTrigger::ACFR_CinematicTrigger()
{
	PrimaryActorTick.bCanEverTick = false;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TriggerBox->SetCollisionResponseToAllChannels(ECR_Ignore);
	TriggerBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	RootComponent = TriggerBox;

	BillboardComponent = CreateEditorOnlyDefaultSubobject < UBillboardComponent>(TEXT("BillboardComponent"));

#if WITH_EDITORONLY_DATA
	if (BillboardComponent)
	{
		BillboardComponent->Sprite = ConstructorHelpers::FObjectFinderOptional<UTexture2D>(TEXT("/Engine/EditorResources/S_LevelSequence")).Get();
		BillboardComponent->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
		BillboardComponent->bHiddenInGame = true;
		BillboardComponent->SetupAttachment(RootComponent);
		BillboardComponent->SetUsingAbsoluteScale(true);
		BillboardComponent->bIsScreenSizeScaled = true;
		BillboardComponent->SetVisibility(true);
	}
#endif
}

void ACFR_CinematicTrigger::BeginPlay()
{
	Super::BeginPlay();

	auto gameMode = Cast<ACFR_IGameMode>(GetWorld()->GetAuthGameMode());
	if (!gameMode)
	{
		UE_LOG(LogTemp, Warning, TEXT("CFR_CinematicTrigger: Could not find game mode."));
		return;
	}

	CinematicManager = gameMode->GetCinematicManager();
	CinematicManager->RegisterTrigger(this);

	if (TriggerType == ECinematicTriggerType::BeginPlay)
	{
		CinematicManager->StartCinematic(this);
	}
	else if (TriggerType == ECinematicTriggerType::Overlap)
	{
		TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ACFR_CinematicTrigger::OnOverlapBegin);
	}
}

void ACFR_CinematicTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	CinematicManager->StartCinematic(this);
}
