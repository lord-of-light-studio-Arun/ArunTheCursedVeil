// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CombatTest_IAttack.generated.h"

/**
 *  CombatTest_IAttack Interface
 *  Provides common functionality to trigger attack animation events.
 */
UINTERFACE(MinimalAPI, NotBlueprintable)
class UCombatTest_IAttack : public UInterface
{
	GENERATED_BODY()
};

class ICombatTest_IAttack
{
	GENERATED_BODY()

public:

	/** Performs an attack's collision check. Usually called from a montage's AnimNotify */
	UFUNCTION(BlueprintCallable, Category = "Attacker")
	virtual void DoAttackTrace(FName DamageSourceBone) = 0;

	/** Performs a combo attack's check to continue the string. Usually called from a montage's AnimNotify */
	UFUNCTION(BlueprintCallable, Category = "Attacker")
	virtual void CheckCombo() = 0;

	/** Performs a charged attack's check to loop the charge animation. Usually called from a montage's AnimNotify */
	UFUNCTION(BlueprintCallable, Category = "Attacker")
	virtual void CheckChargedAttack() = 0;
};
