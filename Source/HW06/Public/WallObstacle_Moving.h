#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WallObstacle_Moving.generated.h"

UCLASS()
class HW06_API AWallObstacle_Moving : public AActor
{
	GENERATED_BODY()
	
public:
	AWallObstacle_Moving();

protected:
	virtual void BeginPlay() override;

	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveRange = 340.f; // �Դٰ��� ���� (�� �̵� �Ÿ�)

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveSpeed = 1.0f; // �ӵ� ������

	FVector StartLocation;
	float RunningTime = 0.f;
};
