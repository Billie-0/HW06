#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JumpPlatform_Rotating.h"
#include "JumpPlatformManager.generated.h"

UCLASS()
class HW06_API AJumpPlatformManager : public AActor
{
	GENERATED_BODY()
	
public:
	AJumpPlatformManager();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

    // ������ Ŭ����
    UPROPERTY(EditAnywhere, Category = "Spawner")
    TSubclassOf<AJumpPlatform_Rotating> JumpPlatformClass;

    UPROPERTY(EditAnywhere, Category = "Spawner")
    int32 PlatformCount = 5;

    UPROPERTY(EditAnywhere, Category = "Spawner")
    FVector SpawnMin;

    UPROPERTY(EditAnywhere, Category = "Spawner")
    FVector SpawnMax;

    // ȸ�� �ӵ� ����
    UPROPERTY(EditAnywhere, Category = "Rotation")
    float MinRotationSpeed = 60.0f;

    UPROPERTY(EditAnywhere, Category = "Rotation")
    float MaxRotationSpeed = 180.0f;

    // ���� �ֱ� ����
    UPROPERTY(EditAnywhere, Category = "Rotation")
    float MinReverseInterval = 2.0f;

    UPROPERTY(EditAnywhere, Category = "Rotation")
    float MaxReverseInterval = 4.0f;

};
