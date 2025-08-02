// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/CFR_PlayerCharacter.h"

#include "AbilitySystem/CFR_AbilitySystemComponent.h"
#include "AbilitySystem/CFR_AttributeSet.h"
#include "Characters/CFR_PlayerController.h"
#include "Components/CFR_CombatAssistComponent.h"
#include "Components/CFR_TargettingComponent.h"
#include "GameFramework/CFR_IGameMode.h"
#include "GameFramework/CFR_PlayerState.h"

#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

ACFR_PlayerCharacter::ACFR_PlayerCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	CombatAssistComponent = CreateDefaultSubobject<UCFR_CombatAssistComponent>(TEXT("Combat Assist Component"));
	TargettingComponent = CreateDefaultSubobject<UCFR_TargettingComponent>(TEXT("Targetting Component"));
}

void ACFR_PlayerCharacter::HandleFinishDying()
{
	OnPlayerHasDied.Execute();

	Super::HandleFinishDying();
}

void ACFR_PlayerCharacter::HandleHealthChanged(const FOnAttributeChangeData& InData)
{
	Super::HandleHealthChanged(InData);
}

void ACFR_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{

		if (const auto PlayerController = Cast<ACFR_PlayerController>(Controller))
		{
			EnhancedInputComponent->BindAction(PauseGameAction, ETriggerEvent::Triggered, PlayerController, &ACFR_PlayerController::HandlePauseGameInput);
		}

		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACFR_PlayerCharacter::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACFR_PlayerCharacter::Look);

		if (const auto CFR_AbilitySystemComponent = Cast<UCFR_AbilitySystemComponent>(AbilitySystemComponent))
		{
			CFR_AbilitySystemComponent->BindDefaultAbilitiesInput(EnhancedInputComponent);
		}
	}
}

void ACFR_PlayerCharacter::PossessedBy(AController* NewController)
{
	/* Init for Server. */
	Super::PossessedBy(NewController);

	InitAbilitySystemInfo();

	const auto AttrSet = GetAbilitySystemComponent()->GetSet<UCFR_AttributeSet>();
	check(AttrSet);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttrSet->GetCurrentHealthAttribute()).AddUObject(this, &ACFR_PlayerCharacter::HandleHealthChanged);

	// Add Input Mapping Context.
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	const auto GameMode = Cast<ACFR_IGameMode>(UGameplayStatics::GetGameMode(this));
	check(GameMode);

	OnPlayerHasDied.BindUObject(GameMode, &ACFR_IGameMode::PlayerLoses);
}

void ACFR_PlayerCharacter::OnRep_PlayerState()
{
	InitAbilitySystemInfo();
}

FGenericTeamId ACFR_PlayerCharacter::GetGenericTeamId() const
{
	return FGenericTeamId(0);
}

void ACFR_PlayerCharacter::SetEnableMoveInput(bool bEnable)
{
	bEnableMoveInput = bEnable;
}

void ACFR_PlayerCharacter::InitAbilitySystemInfo()
{
	ACFR_PlayerState* CFR_PlayerState = GetPlayerState<ACFR_PlayerState>();
	check(CFR_PlayerState);
	UCFR_AbilitySystemComponent* ASC = Cast<UCFR_AbilitySystemComponent>(CFR_PlayerState->GetAbilitySystemComponent());
	check(ASC);
	AbilitySystemComponent = CFR_PlayerState->GetAbilitySystemComponent();
	AttributeSet = CFR_PlayerState->GetAttributeSet();
	ASC->InitAbilityActorInfo(CFR_PlayerState, this);
	ASC->GrantDefaultAbilities();
	ASC->InitializeAttributes();
	UE_LOG(LogTemp, Display, TEXT("AbilitySystemComponent initialized!"));
	InitializeAbilitySystemComponentCallbacks();

	if (OnAbilitySystemComponentInitialized.IsBound())
	{
		OnAbilitySystemComponentInitialized.Broadcast(ASC);
	}
}

void ACFR_PlayerCharacter::Move(const FInputActionValue& Value)
{
	if (!bEnableMoveInput)
		return;

	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ACFR_PlayerCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

float ACFR_PlayerCharacter::GetCharacterLevel() const
{
	const auto CFR_PlayerState = Cast<ACFR_PlayerState>(GetPlayerState());
	check(CFR_PlayerState);

	return CFR_PlayerState->GetCharacterLevel();
}

void ACFR_PlayerCharacter::HandleMeleeAbilityActivated(UGameplayAbility* GameplayAbility)
{
	SetEnableMoveInput(false);
}

void ACFR_PlayerCharacter::HandleMeleeAbilityEnded(UGameplayAbility* GameplayAbility)
{
	SetEnableMoveInput(true);
}

void ACFR_PlayerCharacter::HandleAirAbilityActivated(UGameplayAbility* GameplayAbility)
{
	Super::HandleAirAbilityActivated(GameplayAbility);
	
	GetCharacterMovement()->DisableMovement();
}

void ACFR_PlayerCharacter::HandleAirAbilityEnded(UGameplayAbility* GameplayAbility)
{
	Super::HandleAirAbilityEnded(GameplayAbility);

	GetCharacterMovement()->SetMovementMode(MOVE_Walking);
}
