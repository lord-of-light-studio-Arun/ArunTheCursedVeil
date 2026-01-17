// Fill out your copyright notice in the Description page of Project Settings.


#include "HS_EnemyController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

AHS_EnemyController::AHS_EnemyController(const FObjectInitializer& ObjectInitializer)
{
	BehaviorTreeComp = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BT Component"));
	Blackboard = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BB Component"));
}

void AHS_EnemyController::BeginPlay()
{
	Super::BeginPlay();
	
	RunBehaviorTree(BehaviorTree);
	BehaviorTreeComp->StartTree(*BehaviorTree);
}

void AHS_EnemyController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	if (Blackboard)
		Blackboard->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
}

class UBlackboardComponent* AHS_EnemyController::GetBlackboard() const
{
	return Blackboard;
}
