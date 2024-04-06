
#include "Characters/CFR_PlayerCharacter.h"
#include "Characters/CFR_PlayerCharacterAnimInstance.h"

void UCFR_PlayerCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	PlayerCharacter = Cast<ACFR_PlayerCharacter>(TryGetPawnOwner());
}

void UCFR_PlayerCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);

    if (PlayerCharacter == nullptr)
    {
        PlayerCharacter = Cast<ACFR_PlayerCharacter>(TryGetPawnOwner());
    }

    if (PlayerCharacter == nullptr)
        return;

    const auto Velocity = PlayerCharacter->GetVelocity();
    MovementSpeed = Velocity.Size2D();
}