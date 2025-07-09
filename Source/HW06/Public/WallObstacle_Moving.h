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
	float MoveRange = 340.f; // 왔다갔다 범위 (총 이동 거리)

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveSpeed = 1.0f; // 속도 조절용

	FVector StartLocation;
	float RunningTime = 0.f;
};
