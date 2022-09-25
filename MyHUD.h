#pragma once
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Blueprint/UserWidget.h"
#include "Components/WidgetComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"
#include "MyUserWidget.h"
#include "Robot.h"
#include "MyHUD.generated.h"


UCLASS()
class CARTOON_API AMyHUD : public AHUD
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;
private:


public:
	void UpdateEnergyProgressBar();

	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> Widget;


private:

	ARobot* Robot{};

private:
	UMyUserWidget* MyUserWidget;
};
