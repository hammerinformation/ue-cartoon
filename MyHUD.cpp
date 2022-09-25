#include "MyHUD.h"

void AMyHUD::BeginPlay() {
	Super::BeginPlay();



	if (Widget)
	{
		MyUserWidget = CreateWidget<UMyUserWidget>(GetWorld(), Widget);

		if (MyUserWidget)
		{
			MyUserWidget->AddToViewport();
			if (Robot == nullptr) {
				Robot = Cast<ARobot>(UGameplayStatics::GetActorOfClass(GetWorld(), ARobot::StaticClass()));
				MyUserWidget->EnergyProgressBar->SetPercent(0.f);
				MyUserWidget->Robot = Robot;
			}

		}
	}


}

void AMyHUD::UpdateEnergyProgressBar() {
	MyUserWidget->UpdateEnergyProgressBar();
}