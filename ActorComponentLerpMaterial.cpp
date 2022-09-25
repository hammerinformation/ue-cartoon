

#include "ActorComponentLerpMaterial.h"

UActorComponentLerpMaterial::UActorComponentLerpMaterial()
{

	PrimaryComponentTick.bCanEverTick = true;

}


void UActorComponentLerpMaterial::BeginPlay()
{
	Super::BeginPlay();
	WaterManager = Cast<AWaterManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AWaterManager::StaticClass()));

	Material = GetOwner()->FindComponentByClass<UStaticMeshComponent>()->CreateAndSetMaterialInstanceDynamic(0);
}


void UActorComponentLerpMaterial::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (WaterManager != nullptr) {
		if (WaterManager->bGameIsFinished) {
			Value += DeltaTime / 30.0f;

			Material->SetScalarParameterValue("Alpha", Value);
			if (Value > 1) {
				Value = 1;
			}
		}
	}

}

void UActorComponentLerpMaterial::ChangeColour() {
	bLerp = true;
}
