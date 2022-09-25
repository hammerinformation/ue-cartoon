
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "RobotAIController.h"
#include "Woman.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/UnrealMathUtility.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Character.h"
#include "Robot.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"

#include "Engine.h"
#include "Task_MorphTargets.generated.h"

UCLASS()
class CARTOON_API UTask_MorphTargets : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UTask_MorphTargets(const FObjectInitializer& ObjectInitializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

protected:
	void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds);
private:
	AWoman* Player = nullptr;
	APawn* Pawn;
	ARobotAIController* AIController;
	USkeletalMeshComponent* Body;
	USkeletalMeshComponent* Propeller;

		UPROPERTY(EditAnywhere)
		bool bClose;
};
