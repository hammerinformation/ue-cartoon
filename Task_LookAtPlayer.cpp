// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_LookAtPlayer.h"


UTask_LookAtPlayer::UTask_LookAtPlayer(const FObjectInitializer& ObjectInitializer) {
	NodeName = " Look At Player";
	bNotifyTick = true;
}
EBTNodeResult::Type UTask_LookAtPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto const AIController = Cast<ARobotAIController>(OwnerComp.GetAIOwner());
	Pawn = AIController->GetPawn();
	Player = Cast< AWoman>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	return EBTNodeResult::InProgress;

}

void UTask_LookAtPlayer::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{

	if (Player != nullptr && Pawn != nullptr) {
		FVector Dir = Player-> GetActorLocation() - (FVector::UpVector * 165.0f) - Pawn->GetActorLocation();
		Pawn->SetActorRotation(FMath::Lerp(Pawn->GetActorRotation(), Dir.Rotation(), 0.05f));

	}

	time -= DeltaSeconds;
	if (time <= 0) {
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);

	}



}