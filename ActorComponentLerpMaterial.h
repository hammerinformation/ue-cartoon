
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Materials/MaterialInstance.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine.h"
#include "WaterManager.h"
#include "Kismet/GameplayStatics.h"

#include "Components/StaticMeshComponent.h"
#include "ActorComponentLerpMaterial.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CARTOON_API UActorComponentLerpMaterial : public UActorComponent
{
	GENERATED_BODY()

public:	
	UActorComponentLerpMaterial();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UPROPERTY(EditAnywhere)
		bool bLerp = false;

	UPROPERTY(EditAnywhere)
		UMaterialInstanceDynamic* Material = nullptr;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh = nullptr;



private:
	float Value = 0.0f;
	void ChangeColour();
	AWaterManager* WaterManager{};
};
