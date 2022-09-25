

#include "Tree.h"

ATree::ATree()
{
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
}

void ATree::BeginPlay()
{
	Super::BeginPlay();
	Material = Mesh->CreateAndSetMaterialInstanceDynamic(0);
	bLerp = false;
}
void ATree::ChangeColour() {
	bLerp = true;
}
void ATree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bLerp) {
		Value += DeltaTime / 50.0f;

		Material->SetScalarParameterValue("Alpha", Value);
		if (Value > 1) {
			Value = 1;
		}
	}

}

