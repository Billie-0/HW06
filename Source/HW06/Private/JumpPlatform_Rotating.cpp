#include "JumpPlatform_Rotating.h"
#include "TimerManager.h"


AJumpPlatform_Rotating::AJumpPlatform_Rotating()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Fab/Grass_Block/grass_block.grass_block"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
	
	PrimaryActorTick.bCanEverTick = true;
}

void AJumpPlatform_Rotating::BeginPlay()
{
	Super::BeginPlay();

	// 타이머로 일정 주기마다 방향 반전
	if (ReverseInterval > 0.1f)
	{
		GetWorldTimerManager().SetTimer(
			ReverseTimerHandle,
			this,
			&AJumpPlatform_Rotating::ReverseRotationDirection,
			ReverseInterval,
			true
		);
	}
	
}

void AJumpPlatform_Rotating::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float ActualSpeed = RotationSpeed * Direction * DeltaTime;
	FRotator DeltaRotation = FRotator(0.f, ActualSpeed, 0.f);
	AddActorLocalRotation(DeltaRotation);

}

void AJumpPlatform_Rotating::ReverseRotationDirection()
{
	Direction *= -1;
}