#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Robot.generated.h"

UCLASS()
class CARTOON_API ARobot : public ACharacter
{
	GENERATED_BODY()

public:
	ARobot();

protected:
	virtual void BeginPlay() override;



private:
	float Energy{};
public:
	float GetEnergy();
	void SetEnergy(float);
	void UpdateUi();

	
};
