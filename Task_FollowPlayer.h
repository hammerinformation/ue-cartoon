
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "RobotAIController.h"
#include "Woman.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/UnrealMathUtility.h"

#include "Task_FollowPlayer.generated.h"


UCLASS()
class CARTOON_API UTask_FollowPlayer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UTask_FollowPlayer(const FObjectInitializer& ObjectInitializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
protected:
	void TickTask(UBehaviorTreeComponent& OwnerComp,uint8* NodeMemory,float DeltaSeconds);
private:
	AWoman* Player = nullptr;
};
