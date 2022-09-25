
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TimerManager.h"
#include "Robot.h"
#include "Woman.generated.h"

UCLASS()
class CARTOON_API AWoman : public ACharacter
{
	GENERATED_BODY()

public:
	AWoman();
private:
	bool bCharacterCanJump = true;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	void MoveForward(float Value);

	void MoveRight(float Value);
	void Jump();

private:
	UFUNCTION()
		void SetCharacterCanJump(bool b);
	UPROPERTY(EditAnywhere)
	ARobot* Robot;

	
public:
	UPROPERTY(EditAnywhere)
		class UAnimMontage* JumpMontage;
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }


};
