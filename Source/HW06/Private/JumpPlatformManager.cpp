#include "JumpPlatformManager.h"
#include "JumpPlatform_Rotating.h"
#include "Kismet/KismetMathLibrary.h"

AJumpPlatformManager::AJumpPlatformManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AJumpPlatformManager::BeginPlay()
{
	Super::BeginPlay();

    if (!JumpPlatformClass) return;

    for (int32 i = 0; i < PlatformCount; i++)
    {
        FVector SpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(
            (SpawnMin + SpawnMax) * 0.5f,
            (SpawnMax - SpawnMin) * 0.5f
        );

        FRotator SpawnRotation = FRotator::ZeroRotator;
        FActorSpawnParameters SpawnParams;

        AJumpPlatform_Rotating* NewPlatform = GetWorld()->SpawnActor<AJumpPlatform_Rotating>(
            JumpPlatformClass,
            SpawnLocation,
            SpawnRotation,
            SpawnParams
        );

        if (NewPlatform)
        {
            NewPlatform->RotationSpeed = FMath::RandRange(MinRotationSpeed, MaxRotationSpeed);
            NewPlatform->ReverseInterval = FMath::RandRange(MinReverseInterval, MaxReverseInterval);
        }
    }
}

void AJumpPlatformManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}