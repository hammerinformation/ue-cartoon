

#include "Task_MorphTargets.h"
UTask_MorphTargets::UTask_MorphTargets(const FObjectInitializer& ObjectInitializer) {
	NodeName = "Morph Targets";
	bNotifyTick = true;
}
EBTNodeResult::Type UTask_MorphTargets::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AIController = Cast<ARobotAIController>(OwnerComp.GetAIOwner());
	Pawn = AIController->GetPawn();
	Player = Cast< AWoman>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	ARobot* Robot = Cast<ARobot>(Pawn);
	Body = Robot->GetMesh();
	Propeller = Cast< USkeletalMeshComponent>(Robot->GetMesh()->GetAttachChildren()[0]);

	return EBTNodeResult::InProgress;

}

void UTask_MorphTargets::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	if (bClose) {

		Body->SetMorphTarget("BodyClose", Body->GetMorphTarget("BodyClose") + DeltaSeconds/ 2.5f);
		Propeller->SetMorphTarget("PropellerClose", Propeller->GetMorphTarget("PropellerClose") + DeltaSeconds / 2.5f);


		if (Body->GetMorphTarget("BodyClose") >= 1) {
			Propeller->SetMorphTarget("PropellerClose", 1);
			Body->SetMorphTarget("BodyClose", 1);
			AIController->GetBlackboardComponent()->SetValueAsBool("NearChest", false);

			FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		}
	}
	else {
		Body->SetMorphTarget("BodyClose", Body->GetMorphTarget("BodyClose") - DeltaSeconds / 2.5f);
		Propeller->SetMorphTarget("PropellerClose", Propeller->GetMorphTarget("PropellerClose") - DeltaSeconds / 2.5f);


		if (Body->GetMorphTarget("BodyClose") <= 0) {
			Propeller->SetMorphTarget("PropellerClose", 0);
			Body->SetMorphTarget("BodyClose", 0);
			AIController->GetBlackboardComponent()->SetValueAsBool("NearChest", false);
			FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		}
	}

}
