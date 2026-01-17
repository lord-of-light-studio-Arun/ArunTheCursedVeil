// Fill out your copyright notice in the Description page of Project Settings.

#include "FindPlayerLocationBTTask.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"

UFindPlayerLocationBTTask::UFindPlayerLocationBTTask(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("FindPlayerLocation");
}

EBTNodeResult::Type UFindPlayerLocationBTTask::ExecuteTask(UBehaviorTreeComponent& TreeComponent, uint8* NodeMemory)
{
	UNavigationSystemV1* NavigationSystem = UNavigationSystemV1::GetCurrent(GetWorld());
	
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	APawn* Player = PlayerController->GetPawn();
	
	UBlackboardComponent* Blackboard = Cast<UBlackboardComponent>(TreeComponent.GetAIOwner()->GetComponentByClass(UBlackboardComponent::StaticClass()));
	if (NavigationSystem) Blackboard->SetValueAsVector(GetSelectedBlackboardKey(), Player->GetActorLocation());
	FinishLatentTask(TreeComponent, EBTNodeResult::Succeeded);
	
	return EBTNodeResult::Succeeded;
}
