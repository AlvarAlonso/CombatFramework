// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/CFR_AICharacter.h"

#include "AbilitySystem/CFR_AbilitySystemComponent.h"
#include "AbilitySystem/CFR_AttributeSet.h"
#include "Components/WidgetComponent.h"
#include "Widgets/CFR_DamagePopupWidget.h"
#include "Widgets/CFR_DamageWrapperWidget.h"

ACFR_AICharacter::ACFR_AICharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UCFR_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UCFR_AttributeSet>("AttributeSet");

	CombatTargetWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("CombatTargetWidgetComponent"));
	CombatTargetWidgetComponent->SetupAttachment(RootComponent);

	DamagePopupWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("DamagePopupWidgetcomponent"));
	DamagePopupWidgetComponent->SetupAttachment(RootComponent);

	ConstructorHelpers::FClassFinder<UCFR_DamageWrapperWidget> damageWrapperWidgetFinder(TEXT("/Game/CombatFrameworkContent/UI/Widgets/InGame/WBP_DamagePopupWrapper"));

	if (!damageWrapperWidgetFinder.Succeeded())
		return;

	DamagePopupWidgetComponent->SetWidgetClass(damageWrapperWidgetFinder.Class);
}

FGenericTeamId ACFR_AICharacter::GetGenericTeamId() const
{
	return FGenericTeamId(1);
}

void ACFR_AICharacter::SetCombatTargetWidgetVisibility(bool bVisible)
{
	CombatTargetWidgetComponent->SetVisibility(bVisible);
}

void ACFR_AICharacter::Interact_Implementation(AActor* ActorInteracting)
{
	// TODO: Implement Execution.
}

void ACFR_AICharacter::StartCanInteract_Implementation(AActor* ActorInteracting)
{

}

void ACFR_AICharacter::StopCanInteract_Implementation(AActor* ActorInteracting)
{

}

bool ACFR_AICharacter::CanBeInteractedWith_Implementation(AActor* ActorInteracting)
{
	return false;
}

void ACFR_AICharacter::BeginPlay()
{
	Super::BeginPlay();

	InitAbilitySystemInfo();
	SetCombatTargetWidgetVisibility(false);
}

void ACFR_AICharacter::InitAbilitySystemInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	UCFR_AbilitySystemComponent* CFR_ASC = Cast<UCFR_AbilitySystemComponent>(AbilitySystemComponent);
	check(CFR_ASC);

	CFR_ASC->DefaultAbilitiesInitData = DefaultAbilitiesInitData;
	CFR_ASC->StartupGameplayEffects = StartupGameplayEffects;
	CFR_ASC->GrantDefaultAbilities();
	CFR_ASC->InitializeAttributes();

	const auto AttrSet = Cast<UCFR_AttributeSet>(AttributeSet);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttrSet->GetCurrentHealthAttribute()).AddUObject(this, &ACFR_AICharacter::HandleHealthChanged);
	InitializeAbilitySystemComponentCallbacks();
}

void ACFR_AICharacter::HandleHealthChanged(const FOnAttributeChangeData& InData)
{
	Super::HandleHealthChanged(InData);

	if (auto damagePopupWrapperWidget = Cast<UCFR_DamageWrapperWidget>(DamagePopupWidgetComponent->GetWidget()))
	{
		damagePopupWrapperWidget->AddDamagePopupWidget(InData.OldValue - InData.NewValue);
	}
}

float ACFR_AICharacter::GetCharacterLevel() const
{
	return CharacterLevel;
}
