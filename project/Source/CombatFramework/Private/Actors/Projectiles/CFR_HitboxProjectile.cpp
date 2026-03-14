#include "Actors/Projectiles/CFR_HitboxProjectile.h"

#include "GameFramework/ProjectileMovementComponent.h"

#include "AbilitySystem/CFR_AbilitySystemComponent.h"
#include "AbilitySystem/CFR_AbilitySystemGlobals.h"
#include "Characters/CFR_CharacterBase.h"
#include "Components/CFR_HitboxComponent.h"

ACFR_HitboxProjectile::ACFR_HitboxProjectile()
{
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	HitboxComponent = CreateDefaultSubobject<UCFR_HitboxComponent>(TEXT("HitboxComponent"));
	HitboxComponent->SetupAttachment(RootComponent);
}

void ACFR_HitboxProjectile::BeginPlay()
{
	Super::BeginPlay();

	HitboxComponent->OnHitboxOverlap.AddDynamic(this, &ACFR_HitboxProjectile::OnHitboxOverlap);
}

void ACFR_HitboxProjectile::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	HitboxComponent->OnHitboxOverlap.RemoveDynamic(this, &ACFR_HitboxProjectile::OnHitboxOverlap);
}

void ACFR_HitboxProjectile::OnHitboxOverlap(AActor* OverlappedActor)
{
	auto characterInstigator = Cast<ACFR_CharacterBase>(Instigator);
	auto targetCharacter = Cast<ACFR_CharacterBase>(OverlappedActor);

	if (!characterInstigator || !targetCharacter)
	{
		return;
	}

	auto sourceASC = characterInstigator->GetAbilitySystemComponent();
	auto targetASC = targetCharacter->GetAbilitySystemComponent();

	if (sourceASC && targetASC)
	{
		auto effectContextHandle = sourceASC->MakeEffectContext();
		auto CFREffectContext = static_cast<FCFR_GameplayEffectContext*>(effectContextHandle.Get());

		for (const auto& EffectContext : EffectContextsToApply)
		{
			CFREffectContext->AbilitySourceData = EffectContext.Payload;
			auto outgoingSpec = sourceASC->MakeOutgoingSpec(EffectContext.EffectToApply, 1.0f, effectContextHandle);
			sourceASC->BP_ApplyGameplayEffectSpecToTarget(outgoingSpec, targetASC);
		}
	}
}
