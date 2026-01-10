// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CombatTest_IDamage.generated.h"

/**
 *  CombatDamageable interface
 *  Provides functionality to handle damage, healing, knockback and death
 *  Also provides functionality to warn characters of incoming sources of damage
 */
UINTERFACE(MinimalAPI, NotBlueprintable)
class UCombatTest_IDamage : public UInterface
{
	GENERATED_BODY()
};

class ICombatTest_IDamage
{
	GENERATED_BODY()

public:

	/** Handles damage and knockback events */
	UFUNCTION(BlueprintCallable, Category = "Damageable")
	virtual void ApplyDamage(float Damage, AActor* DamageCauser, const FVector& DamageLocation, const FVector& DamageImpulse) = 0;

	/** Handles death events */
	UFUNCTION(BlueprintCallable, Category = "Damageable")
	virtual void HandleDeath() = 0;
};
