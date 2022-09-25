

#include "Robot.h"
#include "MyHUD.h"
#include "RobotAIController.h"

ARobot::ARobot()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ARobot::BeginPlay()
{
	Super::BeginPlay();
	//MyHud = UGameplayStatics::GetPlayerController(this, 0)->GetHUD<AMyHUD>();



}



void ARobot::SetEnergy(float NewEnergy)
{
	this->Energy = NewEnergy;
	if (Energy == 100.0f) {
		ARobotAIController*	RobotAIController = Cast< ARobotAIController>(GetController());
		RobotAIController->GetBlackboardComponent()->SetValueAsBool("bFinish", true);
	}
}
void ARobot::UpdateUi() {
	AMyHUD* MyHud = Cast<AMyHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
	if (MyHud)
	{
		MyHud->UpdateEnergyProgressBar();
	}

}

float ARobot::GetEnergy()
{
	return this->Energy;
}