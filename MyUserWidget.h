#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Runtime/UMG/Public/Components/ProgressBar.h>
#include "Components/TextBlock.h"

#include "Robot.h"
#include "MyUserWidget.generated.h"

UCLASS()
class CARTOON_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct()override;


public:
	UPROPERTY(meta = (BindWidget))
		UProgressBar* EnergyProgressBar;

	ARobot* Robot = nullptr;

	void UpdateEnergyProgressBar();


	UPROPERTY(meta = (BindWidget))
		UTextBlock* StoryText;

private:
	void EnableStoryText();
	void DisableStoryText();

};
