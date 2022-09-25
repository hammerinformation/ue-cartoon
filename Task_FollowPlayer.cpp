

#include "Task_FollowPlayer.h"

UTask_FollowPlayer::UTask_FollowPlayer(const FObjectInitializer& ObjectInitializer) {
	NodeName = "Follow Player";
	bNotifyTick = true;
}
EBTNodeResult::Type UTask_FollowPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto const AIController = Cast<ARobotAIController>(OwnerComp.GetAIOwner());
	auto const Pawn = AIController->GetPawn();
	Player = Cast< AWoman>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	return EBTNodeResult::InProgress;

}

void UTask_FollowPlayer::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	auto const AIController = Cast<ARobotAIController>(OwnerComp.GetAIOwner());
	auto const Pawn = AIController->GetPawn();
	//AIController->MoveToActor(Player, 30.0f, true);

	if (Player != nullptr) {
		auto RandomValue = FMath::RandRange(-7.0f, 7.0f);
		RandomValue = FMath::Abs(RandomValue) <= 2 ? 5 : RandomValue;
		//AIController->MoveToLocation(Player->GetActorLocation()+FVector(RandomValue,0,0), 150.0f, true);
		AIController->MoveToActor(Player,150,true);
		//FVector Dir = Player->GetActorLocation() - (FVector::UpVector * 165.0f) - Pawn->GetActorLocation();
		//Pawn->SetActorRotation(FMath::Lerp(Pawn->GetActorRotation(), Dir.Rotation(), 0.05f));
		float Distance = FVector::Distance(Pawn->GetActorLocation(), Player->GetActorLocation());
		if (Distance < 300) {
			FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		}
		else {
			//Pawn->SetActorRotation(FMath::Lerp(Pawn->GetActorRotation(), (Player->GetActorLocation() - Pawn->GetActorLocation()).Rotation(), 0.2f));

		}
	}
}
