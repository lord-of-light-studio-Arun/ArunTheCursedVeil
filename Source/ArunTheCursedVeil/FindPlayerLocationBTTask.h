// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "FindPlayerLocationBTTask.generated.h"

UCLASS()
class ARUNTHECURSEDVEIL_API UFindPlayerLocationBTTask : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UFindPlayerLocationBTTask(const FObjectInitializer& ObjectInitializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& TreeComponent, uint8* NodeMemory) override;
};
