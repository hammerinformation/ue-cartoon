// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "RobotAIController.h"
#include "Woman.h"
#include "Task_LookAtPlayer.generated.h"

UCLASS()
class CARTOON_API UTask_LookAtPlayer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()


public:
	UTask_LookAtPlayer(const FObjectInitializer& ObjectInitializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

	UPROPERTY(EditAnywhere)
		float time = 2.0f;

protected:
	void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds);
private:
	AWoman* Player = nullptr;
	APawn* Pawn = nullptr;
	
};
