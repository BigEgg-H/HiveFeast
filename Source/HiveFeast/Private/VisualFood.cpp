// Fill out your copyright notice in the Description page of Project Settings.


#include "VisualFood.h"

#include "Animation/MeshDeformer.h"

AVisualFood::AVisualFood()
{
	PrimaryActorTick.bCanEverTick = true;
}

AVisualIngredient::AVisualIngredient()
{
	PrimaryActorTick.bCanEverTick = true;
	
	IngredientMesh = CreateDefaultSubobject<UStaticMeshComponent>("IngredientMesh");
	SetRootComponent(IngredientMesh);
	IngredientMesh->SetVisibility(false);
}

void AVisualIngredient::SpawnToWorld(const FTransform& SpawnTransform)
{
	SetActorTransform(SpawnTransform);
	IngredientMesh->SetVisibility(true);
	IngredientMesh->SetSimulatePhysics(true);
}

FVisualFoodFeedbackData AVisualIngredient::GetTargetForDish()
{
	FVisualFoodFeedbackData FeedbackData = FVisualFoodFeedbackData();
	FeedbackData.TargetMesh = IngredientMesh->GetStaticMesh();
	FeedbackData.TargetTransform = IngredientMesh->GetComponentTransform();
	return FeedbackData;
}

void AVisualIngredient::StopVisualSimulation()
{
	IngredientMesh->SetSimulatePhysics(false);
}

AVisualFleshIngredient::AVisualFleshIngredient()
{
	PrimaryActorTick.bCanEverTick = true;
	IngredientStaticMesh = nullptr;
	
	IngredientMesh = CreateDefaultSubobject<USkeletalMeshComponent>("IngredientMesh");
	SetRootComponent(IngredientMesh);
	FleshComponent = CreateDefaultSubobject<UFleshComponent>("FleshComponent");
	FleshComponent->AttachToComponent(IngredientMesh,FAttachmentTransformRules::KeepRelativeTransform);
	FleshComponent->SetVisibility(false);
	
	static ConstructorHelpers::FObjectFinder<UObject> TempFleshMeshDeformer(
			TEXT("/Script/OptimusCore.OptimusDeformer'/ChaosFlesh/Deformers/DG_FleshDeformer.DG_FleshDeformer'")
			);
	ensureAlwaysMsgf(TempFleshMeshDeformer.Succeeded(), TEXT("无法加载变形器图!"));
	IngredientMesh->SetMeshDeformer(static_cast<UMeshDeformer*>(TempFleshMeshDeformer.Object));
	
}

void AVisualFleshIngredient::SpawnToWorld(const FTransform& SpawnTransform)
{
	SetActorTransform(SpawnTransform);
	IngredientMesh->SetVisibility(true);
	FleshComponent->EnableSimulationFromActor(SolverActor);
	IngredientMesh->SetSimulatePhysics(true);
	IngredientMesh->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	IngredientMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
}

FVisualFoodFeedbackData AVisualFleshIngredient::GetTargetForDish()
{
	FVisualFoodFeedbackData FeedbackData = FVisualFoodFeedbackData();
	FeedbackData.TargetMesh = IngredientStaticMesh;
	FeedbackData.TargetTransform = IngredientMesh->GetComponentTransform();
	return FeedbackData;
}

void AVisualFleshIngredient::StopVisualSimulation()
{
	IngredientMesh->SetSimulatePhysics(false);
	FleshComponent->DisableSimulation();
}
