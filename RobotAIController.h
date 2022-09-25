#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "AITypes.h"
#include "Navigation/PathFollowingComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "Engine/Engine.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Woman.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "RobotAIController.generated.h"


UCLASS()
class CARTOON_API ARobotAIController : public AAIController
{
	GENERATED_BODY()
public:
		ARobotAIController();

	UPROPERTY(EditAnywhere)
		class UAIPerceptionComponent* PerceptionComp = nullptr;

	UPROPERTY(EditAnywhere)
		class UAISenseConfig_Sight* SightConfig;
	UPROPERTY(EditAnywhere)

		class UAISenseConfig_Hearing* HearingConfig;
	UFUNCTION()
		void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);


	class  AWoman* Player;


	virtual FRotator GetControlRotation() const override;


	UFUNCTION()
		void	OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result);


protected:

	virtual void BeginPlay()override;

};
