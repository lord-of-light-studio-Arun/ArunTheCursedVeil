// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HackSlashCharacter.generated.h"

struct FInputActionValue;

UCLASS()
class ARUNTHECURSEDVEIL_API AHackSlashCharacter : public ACharacter
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = true))
	class USpringArmComponent* SpringArm;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = true))
	class UCameraComponent* Camera;

public:
	// Sets default values for this character's properties
	AHackSlashCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	UAnimMontage* JumpMontage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	UAnimMontage* ComboAttackMontage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	UAnimMontage* ChargedAttackMontage;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called for movement input
	void Move(const FInputActionValue& Value);
	
	virtual void Jump() override;
	
	void ComboAttack();
	
	void ChargedAttack();
	
	bool IsAttacking() const;
	
	int IComboAttackIndex = 0;

	bool bCharging = false;
	bool bCharged = false;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
public:
	UFUNCTION()
	void HandleOnMontageNotifyBegin(FName A_NNotifyName, const FBranchingPointNotifyPayload& A_PBranchingPayload);
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return SpringArm; }

	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return Camera; }
};
