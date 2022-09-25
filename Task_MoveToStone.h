// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "RobotAIController.h"

#include "Task_MoveToStone.generated.h"

UCLASS()
class CARTOON_API UTask_MoveToStone : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UTask_MoveToStone(const FObjectInitializer& ObjectInitializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

	

protected:
	void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds);
private:
	APawn* Pawn = nullptr;



};
