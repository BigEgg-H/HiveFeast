// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ConstructorHelpers.h"
#include "ChaosFleshEngine/Public/ChaosFlesh/FleshComponent.h"
#include "VisualFood.generated.h"

USTRUCT(BlueprintType)
struct FVisualFoodFeedbackData
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere,Category="HiveFeast")
	FTransform TargetTransform = FTransform();

	UPROPERTY(VisibleAnywhere,Category="HiveFeast")
	UStaticMesh* TargetMesh = nullptr;
};

UCLASS(BlueprintType, Blueprintable, Category = "HiveFeast")
class HIVEFEAST_API AVisualFood : public AActor
{
	GENERATED_BODY()
public:
	AVisualFood();
	
	virtual void SpawnToWorld(const FTransform& SpawnTransform){};
	virtual FVisualFoodFeedbackData GetTargetForDish() {return FVisualFoodFeedbackData();};

	UFUNCTION(BlueprintCallable, Category = "HiveFeast")
	virtual void StopVisualSimulation() {};
};

UCLASS(BlueprintType, Category = "HiveFeast")
class HIVEFEAST_API AVisualIngredient : public AVisualFood
{
	GENERATED_BODY()
	
public:
	AVisualIngredient();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "HiveFeast")
	UStaticMeshComponent* IngredientMesh;
	
	virtual void SpawnToWorld(const FTransform& SpawnTransform) override;
	virtual FVisualFoodFeedbackData GetTargetForDish() override;
	virtual void StopVisualSimulation() override;
};

UCLASS(BlueprintType, Category = "HiveFeast")
class HIVEFEAST_API AVisualFleshIngredient : public AVisualFood
{
	GENERATED_BODY()
public:
	AVisualFleshIngredient();
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "HiveFeast")
	USkeletalMeshComponent* IngredientMesh;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "HiveFeast")
	UFleshComponent* FleshComponent;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "HiveFeast")
	UStaticMesh* IngredientStaticMesh;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "HiveFeast")
	ADeformableSolverActor* SolverActor;
	
	virtual void SpawnToWorld(const FTransform& SpawnTransform) override;
	virtual FVisualFoodFeedbackData GetTargetForDish() override;
	virtual void StopVisualSimulation() override;
};