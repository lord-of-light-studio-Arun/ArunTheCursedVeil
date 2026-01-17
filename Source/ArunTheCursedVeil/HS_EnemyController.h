// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "HS_EnemyController.generated.h"

UCLASS()
class ARUNTHECURSEDVEIL_API AHS_EnemyController : public AAIController
{
	GENERATED_BODY()
	
public:
	
	AHS_EnemyController(const FObjectInitializer& ObjectInitializer);
	
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;
	
	class UBlackboardComponent* GetBlackboard() const;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UBehaviorTreeComponent* BehaviorTreeComp;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UBehaviorTree* BehaviorTree;

private:
	class UBlackboardComponent* Blackboard;
};
