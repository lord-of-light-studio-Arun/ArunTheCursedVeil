// Fill out your copyright notice in the Description page of Project Settings.


#include "HackSlashCharacter.h"

#include "InputActionValue.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AHackSlashCharacter::AHackSlashCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	GetCapsuleComponent()->InitCapsuleSize(35.f, 90.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	// GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 400.f;
	SpringArm->bUsePawnControlRotation = true;

	// Create a follow camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void AHackSlashCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (UAnimInstance* PAnimInstance = GetMesh()->GetAnimInstance())
		PAnimInstance->OnPlayMontageNotifyBegin.AddDynamic(this, &AHackSlashCharacter::HandleOnMontageNotifyBegin);
}

void AHackSlashCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	const FVector2D MovementVector = Value.Get<FVector2D>();
	
	if (GetController() != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AHackSlashCharacter::Jump()
{
	if (!IsAttacking())
	{
		Super::Jump();
		if (CanJump())
			if (UAnimInstance* PAnimInstance = GetMesh()->GetAnimInstance())
				PAnimInstance->Montage_Play(JumpMontage);
	}
}

void AHackSlashCharacter::ComboAttack()
{
	bCharging = false;
	if (!IsAttacking() && CanJump())
		if (!bCharged)
			if (UAnimInstance* PAnimInstance = GetMesh()->GetAnimInstance())
				if (ComboAttackMontage)
					PAnimInstance->Montage_Play(ComboAttackMontage);
		else bCharged = false;
	else IComboAttackIndex = 1;
}

void AHackSlashCharacter::ChargedAttack()
{
	if (CanJump())
	{
		bCharging = true;
		FTimerHandle TimerHandle;
		GetWorldTimerManager().SetTimer(TimerHandle, [&]
		{
			if (bCharging)
				if (UAnimInstance* PAnimInstance = GetMesh()->GetAnimInstance()) {
					if (ChargedAttackMontage)
						PAnimInstance->Montage_Play(ChargedAttackMontage);
					bCharging = false;
					bCharged = true;
				}
		}, 1, false);
	}
}

bool AHackSlashCharacter::IsAttacking() const
{
	if (CanJump())
		if (const UAnimInstance* PAnimInstance = GetMesh()->GetAnimInstance())
			if (PAnimInstance->Montage_IsPlaying(ComboAttackMontage))
				return true;
	return false;
}

void AHackSlashCharacter::HandleOnMontageNotifyBegin(FName A_NNotifyName,
                                                     const FBranchingPointNotifyPayload& A_PBranchingPayload)
{
	if (--IComboAttackIndex < 0)
		if (UAnimInstance* PAnimInstance = GetMesh()->GetAnimInstance())
			PAnimInstance->Montage_Stop(0.4, ComboAttackMontage);
}

// Called every frame
void AHackSlashCharacter::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHackSlashCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

