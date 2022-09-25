
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Materials/MaterialInstance.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/StaticMeshComponent.h"

#include "Tree.generated.h"

UCLASS()
class CARTOON_API ATree : public AActor
{
	GENERATED_BODY()

public:
	ATree();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		bool bLerp = false;

	UPROPERTY(EditAnywhere)
		UMaterialInstanceDynamic* Material = nullptr;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh = nullptr;

	void ChangeColour();
private:
	float Value = 0.0f;

};
