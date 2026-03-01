// Fill out your copyright notice in the Description page of Project Settings.


#include "ChasePlayerBTTask.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

UChasePlayerBTTask::UChasePlayerBTTask(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("Chase Player");
}

EBTNodeResult::Type UChasePlayerBTTask::ExecuteTask(UBehaviorTreeComponent& TreeComponent, uint8* NodeMemory)
{
	if (UNavigationSystemV1::GetCurrent(GetWorld()))
	{
		UBlackboardComponent* Blackboard = Cast<UBlackboardComponent>(TreeComponent.GetAIOwner()->GetComponentByClass(UBlackboardComponent::StaticClass()));
		FVector Location = Blackboard->GetValueAsVector(GetSelectedBlackboardKey());
		TreeComponent.GetAIOwner()->MoveToLocation(Location);
	}
	
	FinishLatentTask(TreeComponent, EBTNodeResult::Succeeded);
	
	return EBTNodeResult::Succeeded;
}
