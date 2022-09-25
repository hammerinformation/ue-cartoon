

#include "RobotAIController.h"
#include "Engine/Engine.h"
#include "Kismet/KismetSystemLibrary.h"

ARobotAIController::ARobotAIController() {
	PrimaryActorTick.bCanEverTick = true;
	PerceptionComp = CreateDefaultSubobject< UAIPerceptionComponent>(TEXT("Perception"));
	SetPerceptionComponent(*PerceptionComp);
	SightConfig = CreateDefaultSubobject< UAISenseConfig_Sight>(TEXT("SightConfig"));
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	GetPerceptionComponent()->ConfigureSense(*SightConfig);
	HearingConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("HearingConfig"));
	HearingConfig->DetectionByAffiliation.bDetectEnemies = true;
	HearingConfig->DetectionByAffiliation.bDetectFriendlies = true;
	HearingConfig->DetectionByAffiliation.bDetectNeutrals = true;
	GetPerceptionComponent()->ConfigureSense(*HearingConfig);
	GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &ARobotAIController::OnTargetPerceptionUpdated);

}
void ARobotAIController::BeginPlay()
{
	Super::BeginPlay();
	Player = Cast<AWoman>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	this->ReceiveMoveCompleted.AddDynamic(this, &ARobotAIController::OnMoveCompleted);

}



void ARobotAIController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (Stimulus.WasSuccessfullySensed())
	{
	}

}
void ARobotAIController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
	
	if (Result == EPathFollowingResult::Invalid) {

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Invalid"));
		FLatentActionInfo LatentInfo;
		LatentInfo.CallbackTarget = this;
		UKismetSystemLibrary::MoveComponentTo(GetPawn()->GetRootComponent(),
			Player->GetActorLocation(), (Player->GetActorLocation() - GetPawn()->GetActorLocation()).Rotation(),
			false, false, 4, false, EMoveComponentAction::Move, LatentInfo);


	}
	
}






FRotator ARobotAIController::GetControlRotation() const
{
	if (GetPawn() == nullptr)
	{
		return FRotator();
	}

	return FRotator(0.0f, GetPawn()->GetActorRotation().Yaw, 0.0f);
}