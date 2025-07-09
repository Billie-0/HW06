#include "WallObstacle_Moving.h"

AWallObstacle_Moving::AWallObstacle_Moving()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Fab/CC0_-_Woode_Fence/cc0_woode_fence.cc0_woode_fence"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Fab/CC0_-_Woode_Fence/WoodFence.WoodFence"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
	
	PrimaryActorTick.bCanEverTick = true;

}

void AWallObstacle_Moving::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

void AWallObstacle_Moving::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

	// Sine 기반 진동 (범위: -1 ~ +1)
	float DeltaOffset = FMath::Sin(RunningTime * MoveSpeed) * (MoveRange * 0.5f);

	FVector NewLocation = StartLocation;
	NewLocation.Y += DeltaOffset;

	SetActorLocation(NewLocation);
}