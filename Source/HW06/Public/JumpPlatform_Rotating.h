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

    // ȸ�� �߽� �޽�
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* Mesh;

    // ȸ�� �ӵ� (Yaw ����)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
    float RotationSpeed = 90.0f; // Degrees per second

    // ȸ�� ���� ��ȯ �ֱ�
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
    float ReverseInterval = 3.0f;

    // ���� ȸ�� ���� (1 �Ǵ� -1)
    int32 Direction = 1;

    // Ÿ�̸� �ڵ�
    FTimerHandle ReverseTimerHandle;

    // ���� ���� �Լ�
    UFUNCTION()
    void ReverseRotationDirection();
};
