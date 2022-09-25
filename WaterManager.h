
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sound/SoundBase.h"
#include <GameplayCameras/Public/MatineeCameraShake.h>
#include "Particles/ParticleSystem.h"

#include "WaterManager.generated.h"
class UMatineeCameraShake;

UCLASS()
class CARTOON_API AWaterManager : public AActor
{
	GENERATED_BODY()

public:
	AWaterManager();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere)
		AActor* Waterfall {};

	UPROPERTY(EditAnywhere)
		UParticleSystem* WaterfallBottomFoam {};

	UPROPERTY(EditAnywhere)
		AActor* Water {};
	UPROPERTY(EditAnywhere)
		AActor* BigStone {};

	UPROPERTY(EditAnywhere)

		bool bGameIsFinished = false;


	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> Stone;
	void FinishGame();

	UPROPERTY(EditAnywhere)
		USoundBase* ExplosionSound {};

private:
	AActor* SStone;
	UPROPERTY(EditAnywhere)
		float WaterLerpSpeed{};

public:
	UPROPERTY(EditAnywhere)
		TSubclassOf< UMatineeCameraShake> CameraShake;

};
