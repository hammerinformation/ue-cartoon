#include "MyUserWidget.h"
#include "TimerManager.h"

void UMyUserWidget::NativeConstruct() {
	StoryText->SetVisibility(ESlateVisibility::Hidden);

	FTimerHandle TimerHandle;
	FTimerHandle TimerHandle1;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UMyUserWidget::EnableStoryText, 5.0f, false);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle1, this, &UMyUserWidget::DisableStoryText, 15.0f, false);
}
void UMyUserWidget::UpdateEnergyProgressBar() {

	if (Robot != nullptr) {
		EnergyProgressBar->SetPercent(Robot->GetEnergy() / 100.0f);


		if (Robot->GetEnergy() == 100.0f) {
			EnergyProgressBar->SetRenderOpacity(0.0001f);
		}

	}
}

void UMyUserWidget::EnableStoryText() {
	StoryText->SetVisibility(ESlateVisibility::Visible);	
	
	
}

void UMyUserWidget::DisableStoryText() {
	StoryText->SetVisibility(ESlateVisibility::Hidden);


}