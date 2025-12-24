// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CFR_CharacterBase.h"
#include "AbilitySystem/CFR_AbilitySystemComponent.h"
#include "AI/Enums/CFR_AIEnums.h"

#include "Interfaces/CFR_InteractionInterface.h"

#include "CFR_AICharacter.generated.h"

class UWidgetComponent;
class UCFR_DamagePopupComponent;
class UBehaviorTree;

UENUM(BlueprintType)
enum class ECFR_AICharacterType : uint8
{
	None				UMETA(DisplayName = "None"),
	MeleeAngel			UMETA(DisplayName = "MeleeAngel"),
	DistanceAngel		UMETA(DisplayName = "DistanceAngel"),
	MageAngel			UMETA(DisplayName = "MageAngel"),
	MeleePeasant		UMETA(DisplayName = "MeleePeasant"),
	ShieldPeasant		UMETA(DisplayName = "ShieldPeasant"),
	DistancePeasant		UMETA(DisplayName = "DistancePeasant"),
	SuicidalPeasant		UMETA(DisplayName = "SuicidalPeasant")
};

DECLARE_MULTICAST_DELEGATE_OneParam(FOnHandleDeath, class ACFR_AICharacter*);

UCLASS()
class COMBATFRAMEWORK_API ACFR_AICharacter : public ACFR_CharacterBase, public ICFR_InteractionInterface
{
	GENERATED_BODY()

public:
	ACFR_AICharacter();

	virtual FGenericTeamId GetGenericTeamId() const override;

	ECFR_AICharacterType GetAICharacterType() const;

	void SetCombatTargetWidgetVisibility(bool bVisible);

	void Activate();

	/** Interaction Interface */
	void Interact_Implementation(AActor* ActorInteracting) override;
	void StartCanInteract_Implementation(AActor* ActorInteracting) override;
	void StopCanInteract_Implementation(AActor* ActorInteracting) override;
	bool CanBeInteractedWith_Implementation(AActor* ActorInteracting) override;

	FOnHandleDeath OnHandleDeathEvent;

	UPROPERTY(EditDefaultsOnly, Category = "Abilities")
	TArray<FCFR_AbilityInitData> DefaultAbilitiesInitData;

	/* Initializer gameplay effects. */
	UPROPERTY(EditDefaultsOnly, Category = "Attributes")
	TArray<TSubclassOf<UGameplayEffect>> StartupGameplayEffects;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	TObjectPtr<UBehaviorTree> BehaviorTreeTemplate = nullptr;

	UPROPERTY(EditAnywhere, Category="AI")
	TMap<FGameplayTag, UBehaviorTree*> BehaviorTreesByState;

protected:
	void BeginPlay() override;
	void InitAbilitySystemInfo() override;

	void HandleFinishDying() override;
	void HandleHealthChanged(const FOnAttributeChangeData& InData) override;

	virtual float GetCharacterLevel() const override;

	/** Target widget component to notify the player this is the enemy on target. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UWidgetComponent> CombatTargetWidgetComponent{ nullptr };

	/* Widget component to spawn damage taken values. */
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCFR_DamagePopupComponent> DamagePopupWidgetComponent{ nullptr };

	/** The level of this character, should not be modified directly once it has already spawned */
	UPROPERTY(EditAnywhere, Category = Abilities)
	float CharacterLevel;

	UPROPERTY(EditAnywhere, Category = Abilities, meta = (AllowPrivateAccess = "true"))
	ECFR_AICharacterType AICharacterType;

public:
	// TODO: Should these variables be public?
	// TODO: Is this variable necessary?
	bool bOrbiting = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotationInterpSpeed = 10.0f;
};
