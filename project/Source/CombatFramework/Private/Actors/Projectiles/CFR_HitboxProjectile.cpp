#include "Actors/Projectiles/CFR_HitboxProjectile.h"

#include "AbilitySystem/CFR_AbilitySystemComponent.h"
#include "AbilitySystem/CFR_AbilitySystemGlobals.h"
#include "Characters/CFR_CharacterBase.h"
#include "Components/CFR_HitboxComponent.h"

ACFR_HitboxProjectile::ACFR_HitboxProjectile()
{
	HitboxComponent = CreateDefaultSubobject<UCFR_HitboxComponent>(TEXT("HitboxComponent"));
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

	if (!characterInstigator)
	{
		return;
	}

	auto sourceASC = characterInstigator->GetAbilitySystemComponent();
	auto targetASC = OverlappedActor->FindComponentByClass<UCFR_AbilitySystemComponent>();

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
