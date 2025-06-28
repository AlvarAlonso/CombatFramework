#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CFR_PlayerCharacterAnimInstance.generated.h"

UCLASS()
class COMBATFRAMEWORK_API UCFR_PlayerCharacterAnimInstance : public UAnimInstance
{
    GENERATED_BODY()

public:
	void NativeInitializeAnimation() override;
    void NativeUpdateAnimation(float DeltaSeconds) override;

private:
    UPROPERTY(BlueprintReadOnly, Category = Character, meta = (AllowPrivateAccess = "true"))
    class ACFR_PlayerCharacter* PlayerCharacter = nullptr;

    UPROPERTY(BlueprintReadOnly, Category = Character, meta = (AllowPrivateAccess = "true"))
    float MovementSpeed = 0.0f;

    UPROPERTY(BlueprintReadOnly, Category = Character, meta = (AllowPrivateAccess = "true"))
    bool bDesiresToJump = false;

    UPROPERTY(BlueprintReadOnly, Category = Character, meta = (AllowPrivateAccess = "true"))
    bool bDesiresToDoubleJump = false;
};