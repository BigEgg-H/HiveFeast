// Fill out your copyright notice in the Description page of Project Settings.


#include "HiveFeast/Public/Food.h"

AFood::AFood()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsValidFood = false;

	Flavor = NewObject<UFoodFlavor>();
}

bool AFood::IsValid() const
{
	return bIsValidFood;
}

AIngredient::AIngredient()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsValidFood = false;
	VisualIngredientTemp = nullptr;
	BasicData = FIngredientBasicData();
	
	SpawnParameters = FActorSpawnParameters();
	SpawnParameters.Owner = this;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
}

void AIngredient::Initialize(FIngredientBasicData TempDesc)
{
	ensureAlwaysMsgf(!bIsValidFood,TEXT("重复初始化一个菜品类!"));
	
	bIsValidFood = true;
	BasicData = TempDesc;

	FActorSpawnParameters SpawnParameters_Default = FActorSpawnParameters();
	SpawnParameters_Default.Owner = this;
	SpawnParameters_Default.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParameters_Default.bNoFail = true;
	FTransform DefaultTransform = FTransform();
	if (BasicData.bIsFlesh)
	{
		VisualIngredientTemp = Cast<AVisualFood>(GetWorld()->SpawnActor(AVisualFleshIngredient::StaticClass(), &DefaultTransform, SpawnParameters_Default));
		Cast<AVisualFleshIngredient>(VisualIngredientTemp)->IngredientMesh->SetSkeletalMesh(BasicData.IngredientSkeletalMesh);
		Cast<AVisualFleshIngredient>(VisualIngredientTemp)->IngredientMesh->SetVisibility(false);
		ensureAlwaysMsgf(BasicData.IngredientFleshAsset,TEXT("尝试将无效的Flesh资产绑定到Ingredient!"));
		if (BasicData.IngredientFleshAsset)
			Cast<AVisualFleshIngredient>(VisualIngredientTemp)->FleshComponent->SetRestCollection(BasicData.IngredientFleshAsset);
		Cast<AVisualFleshIngredient>(VisualIngredientTemp)->IngredientStaticMesh = BasicData.IngredientStaticMesh;
	}
	else
	{
		VisualIngredientTemp = Cast<AVisualFood>(GetWorld()->SpawnActor(AVisualIngredient::StaticClass(), &DefaultTransform, SpawnParameters_Default));
		Cast<AVisualIngredient>(VisualIngredientTemp)->IngredientMesh->SetStaticMesh(BasicData.IngredientStaticMesh);
		Cast<AVisualIngredient>(VisualIngredientTemp)->IngredientMesh->SetVisibility(false);
	}
	SpawnParameters.Template = VisualIngredientTemp;
}

FDishBasicData AIngredient::CreateDishBasicData()
{
	FDishBasicData Buffer = FDishBasicData();
	Buffer.IngredientFlavor = Flavor;
	Buffer.TargetStaticMesh = BasicData.IngredientStaticMesh;
	Buffer.IsDrink = false;
	Buffer.FlavorWeight = 1.0;
	for (auto Element : Ingredients)
	{
		Buffer.TargetTransforms.Add(Element->GetActorTransform());
	}
	return Buffer;
}

AVisualFood* AIngredient::SpawnAt(const FTransform& TargetTransform)
{
	ensureAlwaysMsgf(bIsValidFood,TEXT("放置未初始化的食材!"));
	
	if (BasicData.bIsFlesh)
	{
		ensureAlwaysMsgf(SolverActor,TEXT("未设置变形器解算器对象,无法生成\"肉体\"食材!"));
		if (!SolverActor)
			return nullptr;
		AVisualFleshIngredient* Buffer = Cast<AVisualFleshIngredient>(
			GetWorld()->SpawnActor(AVisualFleshIngredient::StaticClass(), &TargetTransform, SpawnParameters)
			);
		Ingredients.Add(Buffer);
		Buffer->SolverActor = SolverActor;
		Buffer->SpawnToWorld(TargetTransform);
		return Buffer;
	}
	else
	{
		AVisualIngredient* Buffer = Cast<AVisualIngredient>(
			GetWorld()->SpawnActor(AVisualIngredient::StaticClass(), &TargetTransform, SpawnParameters)
			);
		Ingredients.Add(Buffer);
		Buffer->SpawnToWorld(TargetTransform);
		return Buffer;
	}
}

ADrink::ADrink()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsValidFood = false;
}

void ADrink::Initialize(FDrinkBasicData TempDesc)
{
	ensureAlwaysMsgf(!bIsValidFood,TEXT("重复初始化一个菜品类!"));
	
	bIsValidFood = true;
	//TODO:从描述符初始化液态食材
}

ADish::ADish()
{
	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(DefaultRoot);
	
	PrimaryActorTick.bCanEverTick = true;
	bIsValidFood = false;
}

void ADish::Initialize(TArray<FDishBasicData> Data)
{
	ensureAlwaysMsgf(!bIsValidFood,TEXT("重复初始化一个菜品类!"));

	bIsValidFood = true;
	BasicData = Data;
	
	for (auto Element : Data)
	{
		Flavor->operator+=(Element.IngredientFlavor->operator*(Element.FlavorWeight));
		if (Element.IsDrink)
		{
			//TODO: Initialize by drink
		}
		else
		{
			for (auto TransformElement : Element.TargetTransforms)
			{
				UStaticMeshComponent* Buffer = Cast<UStaticMeshComponent>(AddComponentByClass(
					UStaticMeshComponent::StaticClass(), true, TransformElement, false
				));
				Buffer->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
				Buffer->SetStaticMesh(Element.TargetStaticMesh);
				//
				// 在这里初始化菜品中的每一个静态网格体组件，设置其初始参数
				//
				Buffer->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			}
		}
	}
}