// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystem/CFR_AttributeSet.h"
#include "AbilitySystem/CFR_BlueprintFunctionLibrary.h"
#include "Characters/CFR_CharacterBase.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UCFR_AttributeSet::UCFR_AttributeSet()
{
	InitCurrentHealth(100.0f);
	InitMaxHealth(100.0f);
	InitCurrentMana(100.0f);
	InitMaxMana(100.0f);
	InitStrength(10.0f);
}

void UCFR_AttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	DOREPLIFETIME_CONDITION_NOTIFY(UCFR_AttributeSet, CurrentHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCFR_AttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCFR_AttributeSet, CurrentMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCFR_AttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCFR_AttributeSet, Strength, COND_None, REPNOTIFY_Always);
}

void UCFR_AttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetCurrentHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
	}
	if (Attribute == GetCurrentManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxMana());
	}
	if (Attribute == GetStrengthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, FLT_MAX);
	}
	if (Attribute == GetDamageAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, FLT_MAX);
	}
}

void UCFR_AttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FCFR_EffectProperties Properties;
	SetEffectProperties(Data, Properties);

	UE_LOG(LogTemp, Warning, TEXT("PostGameplayEffectExecute"));

	
	if (Data.EvaluatedData.Attribute == GetDamageAttribute())
	{
		UE_LOG(LogTemp, Warning, TEXT("SetCurrentHealth"));

		if (GetDamage() > 0.0f)
		{
			const float NewCurrentHealth = GetCurrentHealth() - GetDamage();
			SetCurrentHealth(FMath::Clamp(NewCurrentHealth, 0.0f, GetMaxHealth()));
			
			auto CharacterBase = Cast<ACFR_CharacterBase>(Properties.TargetCharacter);
			if (CharacterBase)
			{
				if (NewCurrentHealth < 0.0f)
				{
					// TODO: Should everything related to combat be managed by an interface?
					CharacterBase->Die();
				}
				else
				{
					// TODO: Pass the position hit by the hitbox here.
					auto EffectCauser = Data.EffectSpec.GetContext().GetEffectCauser();
					UCFR_BlueprintFunctionLibrary::RotateDirectlyTowardsActor(Properties.TargetAvatarActor, EffectCauser, false);
					FGameplayTagContainer TagContainer;
					TagContainer.AddTag(FGameplayTag::RequestGameplayTag("GameplayAbility.ID.HitReact"));
					Properties.TargetASC->TryActivateAbilitiesByTag(TagContainer);
				}
			}
		}

		SetDamage(0.0f);
	}
}

void UCFR_AttributeSet::OnRep_CurrentHealth(const FGameplayAttributeData OldCurrentHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCFR_AttributeSet, CurrentHealth, OldCurrentHealth);
}

void UCFR_AttributeSet::OnRep_MaxHealth(const FGameplayAttributeData OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCFR_AttributeSet, MaxHealth, OldMaxHealth);
}

void UCFR_AttributeSet::OnRep_CurrentMana(const FGameplayAttributeData OldCurrentMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCFR_AttributeSet, CurrentMana, OldCurrentMana);
}

void UCFR_AttributeSet::OnRep_MaxMana(const FGameplayAttributeData OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCFR_AttributeSet, MaxMana, OldMaxMana);
}

void UCFR_AttributeSet::OnRep_Strength(const FGameplayAttributeData OldStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCFR_AttributeSet, Strength, OldStrength);
}

void UCFR_AttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data, FCFR_EffectProperties& Props) const
{
	Props.EffectContextHandle = Data.EffectSpec.GetContext();
	Props.SourceASC = Props.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

	if (IsValid(Props.SourceASC) && Props.SourceASC->AbilityActorInfo.IsValid() && Props.SourceASC->AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.SourceAvatarActor = Props.SourceASC->AbilityActorInfo->AvatarActor.Get();
		Props.SourceController = Props.SourceASC->AbilityActorInfo->PlayerController.Get();
		if (Props.SourceController == nullptr && Props.SourceAvatarActor != nullptr)
		{
			if (const APawn* Pawn = Cast<APawn>(Props.SourceAvatarActor))
			{
				Props.SourceController = Pawn->GetController();
			}
		}
		if (Props.SourceController)
		{
			Props.SourceCharacter = Cast<ACharacter>(Props.SourceController->GetPawn());
		}
	}

	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		Props.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		Props.TargetCharacter = Cast<ACharacter>(Props.TargetAvatarActor);
		Props.TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Props.TargetAvatarActor);
	}
}
