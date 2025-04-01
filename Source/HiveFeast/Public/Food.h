// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HiveFeast/Public/FoodBase.h"
#include "HiveFeast/Public/VisualFood.h"
#include "Food.generated.h"

/*所有食物的基类,储存了食物具有的共同成员函数和变量.抽象类,不应该被直接实例化使用.*/
UCLASS(BlueprintType, abstract, Category = "HiveFeast")
class HIVEFEAST_API AFood : public AActor
{
	GENERATED_BODY()
	
public:	
	AFood();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "HiveFeast")
	UFoodFlavor* Flavor;
	
	bool bIsValidFood;
};

/*所有食材的基类,提供了食材处理相关的方法.*/
UCLASS(BlueprintType,Blueprintable, Category = "HiveFeast")
class HIVEFEAST_API AIngredient : public AFood
{
	GENERATED_BODY()

public:
	AIngredient();

	/*可视化食材模板,除非为实现高级功能,该成员只用于内部回调.*/
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "HiveFeast")
	AVisualFood* VisualIngredientTemp;

	/*存储食材的基本数据.*/
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "HiveFeast")
	FIngredientBasicData BasicData;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "HiveFeast")
	TSet<AVisualFood*> Ingredients;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "HiveFeast")
	ADeformableSolverActor* SolverActor;

	/*用描述符初始化一个食材类.比较耗时,不应在性能敏感处使用.*/
	UFUNCTION(BlueprintCallable, Category = "HiveFeast")
	void InitializeFromGoods(FIngredientBasicData TempDesc);

	/*在指定位置生成食材*/
	UFUNCTION(BlueprintCallable, Category = "HiveFeast")
	void SpawnIngredientAt(const FTransform& TargetTransform);

private:
	FActorSpawnParameters SpawnParameters;
};

/*所有液态食材的基类,储存了液态食材的相关处理办法.*/
UCLASS(BlueprintType,Blueprintable, Category = "HiveFeast", Experimental)
class HIVEFEAST_API ADrink : public AFood
{
	GENERATED_BODY()

public:
	ADrink();

	UFUNCTION(BlueprintCallable, Category = "HiveFeast")
	void InitializeFromGoods(FDrinkBasicData TempDesc);
};

/*所有菜品的基类,表述一个可提交的菜肴对象,包含一些相关的处理方法.*/
UCLASS(BlueprintType,Blueprintable, Category = "HiveFeast", Experimental)
class HIVEFEAST_API ADish : public AFood
{
	GENERATED_BODY()

public:
	ADish();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "HiveFeast")
	USceneComponent* DefaultRoot;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "HiveFeast")
	FDishBasicData BasicData;
	
	UFUNCTION(BlueprintCallable, Category = "HiveFeast")
	void Initialize(FDishBasicData Data);
	
	UFUNCTION(BlueprintCallable, Category = "HiveFeast", meta=(DeprecatedFunction, DeprecationMessage="使用Initialize()函数代替该函数."))
	void InitializeFromIngredient(TSet<AIngredient*> OriginalIngredient);
	
	UFUNCTION(BlueprintCallable, Category = "HiveFeast", meta=(DeprecatedFunction, DeprecationMessage="使用Initialize()函数代替该函数."))
	void InitializeFromDrink(ADrink* OriginalDrink,TSet<AIngredient*> OriginalIngredient);
	
};
