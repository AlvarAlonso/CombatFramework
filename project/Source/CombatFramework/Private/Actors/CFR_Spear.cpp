#include "Actors/CFR_Spear.h"

#include "Characters/CFR_AICharacter.h"
#include "Components/CFR_HitboxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

ACFR_Spear::ACFR_Spear()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	SpearMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpearMesh"));
	SpearMesh->SetupAttachment(Root);
	HitboxComponent->SetupAttachment(Root);
}

void ACFR_Spear::BeginPlay()
{
	Super::BeginPlay();
}

void ACFR_Spear::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bLaunched)
		return;

	const auto CasterLocation = Instigator->GetActorLocation();
	const auto CasterRight = Instigator->GetActorRightVector();
	const auto CasterForward = Instigator->GetActorForwardVector();

	auto CasterOffset = FVector(0.0f);
	CasterOffset = CasterRight.RotateAngleAxis(Angle, CasterForward) * DistanceFromCaster;

	SetActorLocation(CasterLocation + CasterOffset);
	SetActorRotation(Instigator->GetActorRotation());
}

void ACFR_Spear::LaunchSpear(const AActor* InTargetActor)
{
	bLaunched = true;
	SetLifeSpan(SecondsAlive);

	const auto projectileSpeed = ProjectileMovementComponent->InitialSpeed;
	auto velocity = GetActorForwardVector() * projectileSpeed;

	if (InTargetActor)
	{
		if (auto targetCharacter = Cast<ACFR_AICharacter>(InTargetActor))
		{
			const auto targetLocation = targetCharacter->GetActorLocation();
			const auto spearLocation = GetActorLocation();
			const auto direction = (targetLocation - spearLocation).GetSafeNormal();
			velocity = direction * projectileSpeed;
			ProjectileMovementComponent->HomingTargetComponent = targetCharacter->GetRootComponent();
		}
	}

	ProjectileMovementComponent->Velocity = velocity;
}
