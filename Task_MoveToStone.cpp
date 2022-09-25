#include "Task_MoveToStone.h"
#include "Kismet/KismetMathLibrary.h"
#include "WaterManager.h"
#include "Kismet/GameplayStatics.h"


UTask_MoveToStone::UTask_MoveToStone(const FObjectInitializer& ObjectInitializer) {
	NodeName = "Task MoveToStone ";
	bNotifyTick = true;
}
EBTNodeResult::Type UTask_MoveToStone::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	auto const AIController = Cast<ARobotAIController>(OwnerComp.GetAIOwner());
	Pawn = AIController->GetPawn();
	AIController->GetBlackboardComponent()->SetValueAsBool("bFinish", true);
	return EBTNodeResult::InProgress;

}

void UTask_MoveToStone::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{


	FVector Target(12093.897461f, -4432.494141f, 3636.145996f);
	float Distance = FVector::Distance(Pawn->GetActorLocation(), Target);
	//float Speed = 0.0004f;

	float Speed = 0.001f;
	if (Distance <= 6000.0f) {
		Speed = 0.005f;
	}
	Pawn->SetActorLocation(FMath::Lerp(Pawn->GetActorLocation(), Target, Speed));

	if (Distance <= 100.0f) {
		OwnerComp.StopTree(EBTStopMode::Safe);
		Pawn->SetActorScale3D(FVector(0.01f, 0.01f, 0.01f));
		AWaterManager* WaterManager = Cast<AWaterManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AWaterManager::StaticClass()));
		if (WaterManager != nullptr)
			WaterManager->FinishGame();
	}

	Pawn->SetActorRotation(FMath::Lerp(Pawn->GetActorRotation(), (Target - Pawn->GetActorLocation()).Rotation(), 0.2f));

}
