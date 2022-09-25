// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_CircleMovement.h"


UTask_CircleMovement::UTask_CircleMovement(const FObjectInitializer& ObjectInitializer) {
	NodeName = "Circle Movement";
	bNotifyTick = true;
}
EBTNodeResult::Type UTask_CircleMovement::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	TempTime = UGameplayStatics::GetRealTimeSeconds(GetWorld());

	auto const AIController = Cast<ARobotAIController>(OwnerComp.GetAIOwner());
	Pawn = AIController->GetPawn();
	Player = Cast< AWoman>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	return EBTNodeResult::InProgress;

}

void UTask_CircleMovement::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{


	if (Player != nullptr && Pawn != nullptr) {
		auto RealTimeSeconds = UGameplayStatics::GetRealTimeSeconds(GetWorld());
		float X = FMath::Cos((Frequency * RealTimeSeconds)) * Amplitude;
		float Y = FMath::Sin((Frequency * RealTimeSeconds)) * Amplitude;
		FVector NewLoc(X, Y, 0);
		FVector GetActorLocation = Pawn->GetActorLocation();
		FVector GetPlayerLocation = Player->GetActorLocation();
		FVector Target = NewLoc + GetPlayerLocation;

		Pawn->SetActorLocation(FMath::Lerp(GetActorLocation, Target, 0.005f));

		float Distance = FVector::Distance(GetActorLocation, Player->GetActorLocation());
		FVector Dir = GetPlayerLocation - (FVector::UpVector * 165.0f) - GetActorLocation;
		Pawn->SetActorRotation(FMath::Lerp(Pawn->GetActorRotation(), Dir.Rotation(), 0.5f));

		//(TempTime + Time) >= RealTimeSeconds || 
		if (Player->GetVelocity().Size() > 0.f) {
			FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);

		}
	}
}
