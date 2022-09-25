// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "RobotAIController.h"
#include "Woman.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/UnrealMathUtility.h"
#include "Misc/DateTime.h"
#include "GameFramework/FloatingPawnMovement.h"

#include "Task_CircleMovement.generated.h"

/**
 * 
 */
UCLASS()
class CARTOON_API UTask_CircleMovement : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UTask_CircleMovement(const FObjectInitializer& ObjectInitializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	UPROPERTY(EditAnywhere)
		float Frequency = 1.0f;
	UPROPERTY(EditAnywhere)

		float Amplitude = 1.0f;
	UPROPERTY(EditAnywhere)

	float Time;


protected:
	void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds);
private:
	AWoman* Player = nullptr;
	APawn* Pawn = nullptr;
	float TempTime;
};
