#include "WaterManager.h"
#include <Runtime\Engine\Classes\Engine\World.h>
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"

#include "MatineeCameraShake.h"
#include "Camera/PlayerCameraManager.h"

AWaterManager::AWaterManager()
{
	PrimaryActorTick.bCanEverTick = true;
	if (BigStone != nullptr) {
		//BigStone->SetActorHiddenInGame(true);
	}
	if (Water != nullptr) {
		Water->SetActorHiddenInGame(true);
	}
	if (Waterfall != nullptr) {
		Waterfall->SetActorHiddenInGame(true);
	}

}

void AWaterManager::BeginPlay()
{
	Super::BeginPlay();


}

void AWaterManager::FinishGame() {
	//if (BigStone) { BigStone->SetActorHiddenInGame(false); }
	if (Water) { Water->SetActorHiddenInGame(false); }
	if (Waterfall) { Waterfall->SetActorHiddenInGame(false); }

	FVector Pos = BigStone->GetActorLocation();
	FRotator Rot = BigStone->GetActorRotation();

	BigStone->Destroy();

	SStone = GetWorld()->SpawnActor<AActor>(Stone, Pos, Rot);
	if (ExplosionSound) {
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), ExplosionSound, SStone->GetActorLocation(), 1.0f, 1.0f, 0.0f);

	}
	bGameIsFinished = true;
	APlayerCameraManager* PlayerCameraManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
	if (PlayerCameraManager)
		PlayerCameraManager->StartCameraShake(CameraShake, 1.0f);

	if (WaterfallBottomFoam) {
		FTransform T;
		T.SetLocation(FVector(11690.0f, -2395.00f, -450.00f));
		T.SetScale3D(FVector::OneVector * 3.0f);


		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), WaterfallBottomFoam, T, false);
	}
}
void AWaterManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bGameIsFinished && Water != nullptr) {
		FVector NewScale(200.0f, 200.0f, 1.0f);
		Water->SetActorScale3D(FMath::Lerp(Water->GetActorScale3D(), NewScale, DeltaTime * WaterLerpSpeed));
		if (Water->GetActorScale3D().X > 180.0f) {
			//	if (BigStone) { BigStone->SetActorHiddenInGame(false); }
			Water->SetActorLocation(FMath::Lerp(Water->GetActorLocation(), FVector(11771.0f, -3443.0f, -350.0f), DeltaTime * WaterLerpSpeed));

		}
		if (SStone) {
			FVector TargetScale = FMath::Lerp(SStone->GetActorScale3D(), FVector::ZeroVector, 0.001f);

			SStone->SetActorRelativeScale3D(TargetScale);

			if (SStone->GetActorScale3D().Z < 0.1f) {
				//	SStone->Destroy();
			}
		}
		if (BigStone) {
			return;

			/*
			FVector TargetScale = FMath::Lerp(BigStone->GetActorScale3D(), FVector::ZeroVector, 0.01f);

			BigStone->SetActorRelativeScale3D(TargetScale);

			if (BigStone->GetActorScale3D().Z < 0.1f) {
				BigStone->Destroy();
			}

			*/
		}
	}


}

