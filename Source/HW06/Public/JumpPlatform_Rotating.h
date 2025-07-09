#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JumpPlatform_Rotating.generated.h"

UCLASS()
class HW06_API AJumpPlatform_Rotating : public AActor
{
	GENERATED_BODY()
	
public:	
	AJumpPlatform_Rotating();

protected:
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* Material0;
	UPROPERTY(EditAnywhere)
	UMaterialInterface* Material1;
	UPROPERTY(EditAnywhere)
	UMaterialInterface* Material2;
	UPROPERTY(EditAnywhere)
	UMaterialInterface* Material3;
	UPROPERTY(EditAnywhere)
	UMaterialInterface* Material4;
    
    virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

    // 회전 중심 메쉬
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* Mesh;

    // 회전 속도 (Yaw 기준)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
    float RotationSpeed = 90.0f; // Degrees per second

    // 회전 방향 전환 주기
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
    float ReverseInterval = 3.0f;

    // 현재 회전 방향 (1 또는 -1)
    int32 Direction = 1;

    // 타이머 핸들
    FTimerHandle ReverseTimerHandle;

    // 방향 반전 함수
    UFUNCTION()
    void ReverseRotationDirection();
};
