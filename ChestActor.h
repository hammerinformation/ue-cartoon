#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/World.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine.h"
#include "Robot.h"
#include "RobotAIController.h"
#include "ChestActor.generated.h"

UCLASS()
class CARTOON_API AChestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AChestActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* Chest;
	UPROPERTY(EditAnywhere)
			UBoxComponent* Trigger;
	UPROPERTY(EditAnywhere)
		USceneComponent* CollectibleObject;
	UFUNCTION()
		void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);
	UPROPERTY(EditAnywhere)
	ARobot* Robot=nullptr;
	ARobotAIController* RobotAIController;

	UFUNCTION()
		void OnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor, 
			UPrimitiveComponent* OtherComp, 
			int32 OtherBodyIndex);


private:
	bool bChestOpen = false;
	void Open();
	float Value = 0.0f;

	void UpdateHud();
};
