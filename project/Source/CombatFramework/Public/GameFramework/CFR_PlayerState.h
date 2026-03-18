#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"

#include "CFR_PlayerState.generated.h"

class UAttributeSet;

class UCFR_AbilitySystemComponent;

UCLASS()
class ACFR_PlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	ACFR_PlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }
	float GetCharacterLevel() const { return CharacterLevel; }

protected:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCFR_AbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	UPROPERTY(EditDefaultsOnly)
	float CharacterLevel;
};
