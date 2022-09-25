

#include "ChestActor.h"

AChestActor::AChestActor()
{
	PrimaryActorTick.bCanEverTick = true;
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Chest = CreateDefaultSubobject<USkeletalMeshComponent >(TEXT("Chest"));
	RootComponent = Chest;
	Trigger->SetupAttachment(GetRootComponent());
	CollectibleObject = CreateDefaultSubobject<USceneComponent >(TEXT("CollectibleObject"));
	CollectibleObject->SetupAttachment(GetRootComponent());

}

void AChestActor::BeginPlay()
{
	Super::BeginPlay();
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AChestActor::OnComponentBeginOverlap);
	Trigger->OnComponentEndOverlap.AddDynamic(this, &AChestActor::OnComponentEndOverlap);
	Chest->SetMorphTarget("ChestOpen", 0);
	CollectibleObject->SetWorldScale3D(FVector::OneVector / 1000.0f);
	CollectibleObject->SetHiddenInGame(true);
	if (Robot == nullptr) {
		for (TActorIterator<AActor> It(GetWorld()); It; ++It)
		{
			AActor* Actor = *It;
			if (Actor->ActorHasTag(FName(TEXT("Robot"))))
			{
				Robot = Cast<ARobot>(Actor);
				RobotAIController = Cast< ARobotAIController>(Robot->GetController());
			}


		}
	}


}

void AChestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bChestOpen && CollectibleObject)
	{
		CollectibleObject->SetHiddenInGame(false);

		Value += (DeltaTime / 1.0f);

		if (Value >= 1) {
			Value = 1;

			if (Robot != nullptr) {

				FVector Location = FMath::Lerp(CollectibleObject->GetComponentLocation(), Robot->GetActorLocation() + FVector::UpVector * 50.0f, 0.074f);
				FVector Scale = FMath::Lerp(CollectibleObject->GetComponentScale(), FVector::ZeroVector, 0.03f);
				CollectibleObject->SetWorldLocation(Location);
				CollectibleObject->SetWorldScale3D(Scale);
				
				if (FVector::Distance(CollectibleObject->GetComponentLocation(), Robot->GetActorLocation() + FVector::UpVector * 150.0f) < 10) {

					CollectibleObject->SetHiddenInGame(true);
					CollectibleObject->SetupAttachment(Robot->GetRootComponent());
					CollectibleObject->SetWorldLocation(FVector::OneVector + FVector::UpVector * 9999);

					CollectibleObject->DestroyComponent();
					SetLifeSpan(30.0f);
					bChestOpen = false;
					

				}
			}

		}
		Chest->SetMorphTarget("ChestOpen", Value);

	}

}
void AChestActor::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Player") && Robot != nullptr && Chest->GetMorphTarget("ChestOpen") < 1.0f) {

		if (RobotAIController->GetBlackboardComponent()->GetValueAsBool("NearChest") == false) {
			CollectibleObject->SetWorldScale3D(FVector::OneVector);

			OtherActor->FindComponentByClass< UCharacterMovementComponent>()->MaxWalkSpeed = 350.0f;
			FTimerHandle TimerHandle;
			RobotAIController->GetBlackboardComponent()->SetValueAsBool("NearChest", true);
			GetWorldTimerManager().SetTimer(TimerHandle, this, &AChestActor::UpdateHud, 2.0f, false);

			Open();
		}

	}
}
void  AChestActor::UpdateHud() {
	Robot->SetEnergy(Robot->GetEnergy() + 20);
	Robot->UpdateUi();
	RobotAIController->GetBlackboardComponent()->SetValueAsBool("NearChest", false);

}
void AChestActor::Open() {

	bChestOpen = true;
}



void AChestActor::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex) {
	if (OtherActor->ActorHasTag("Player") && Robot != nullptr) {

		
		OtherActor->FindComponentByClass< UCharacterMovementComponent>()->MaxWalkSpeed = 600.0f;

		//	RobotAIController->GetBlackboardComponent()->SetValueAsBool("NearChest", false);

		Trigger->DestroyComponent();
		SetLifeSpan(5.0f);

	}
}