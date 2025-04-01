#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChaosFleshEngine/Public/ChaosFlesh/FleshComponent.h"
#include "FoodFlavor.h"
#include "FoodBase.generated.h"

/*用于初始化食材的描述结构体*/
USTRUCT(BlueprintType, Blueprintable, Category = "HiveFeast")
struct FIngredientBasicData
{
	GENERATED_BODY()

	/*是否为"肉体"食材."肉体"食材将启用Flesh组件并使用骨骼网格体.否则将禁用Flesh并且使用静态网格体.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	bool bIsFlesh;
	
	/*(可选的)食材的骨骼网格体.用来显示"肉体"食材,可视化组装过程,并且绑定Flesh功能.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	USkeletalMesh* IngredientSkeletalMesh;

	/*(可选的)食材的Flesh资产.用于自动绑定Flesh功能.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	UFleshAsset* IngredientFleshAsset;

	/*食材的静态网格体.用来显示"非肉体"食材,并且完成一些特殊操作,可视化组装过程.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	UStaticMesh* IngredientStaticMesh;

	/*食材的默认评分.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	TMap<EFoodColor,double> ColorScore;

	/*食材的默认评分.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	TMap<EFoodAroma,double> AromaScore;

	/*食材的默认评分.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	TMap<EFoodTaste,double> TasteScore;
	
};

/*用于初始化液体食材的描述结构体*/
USTRUCT(BlueprintType, Blueprintable, Category = "HiveFeast")
struct FDrinkBasicData
{
	GENERATED_BODY()
	
};

USTRUCT(BlueprintType, Blueprintable, Category = "HiveFeast")
struct FVisualIngredientBasicData
{
	GENERATED_BODY()
	
};

USTRUCT(BlueprintType, Blueprintable, Category = "HiveFeast")
struct FDishBasicData
{
	GENERATED_BODY()
	
};
