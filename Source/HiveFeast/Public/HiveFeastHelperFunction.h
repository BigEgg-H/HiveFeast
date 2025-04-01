// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HiveFeast/Public/Food.h"
#include "HiveFeastHelperFunction.generated.h"

/*游戏项目通用辅助函数*/
UCLASS()
class HIVEFEAST_API UHiveFeastHelperFunction : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/*计算给定所有食品的综合总平均分*/
	UFUNCTION(BlueprintCallable, Category = "HiveFeast", meta=(DeprecatedFunction))
	static double ComprehensiveScore(TSet<AFood*> SourceFood);

	/*按照给定的权重,计算给定所有食品的综合总分*/
	UFUNCTION(BlueprintCallable, Category = "HiveFeast", meta=(DeprecatedFunction))
	static double ComprehensiveScoreByWeight(TSet<AFood*> SourceFood,FFlavorWeight Weight);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Add", CompactNodeTitle = "+", Keywords = "+ add plus"), Category = "HiveFeast")
	static UFoodFlavor* AddFoodFlavor(UFoodFlavor* A,UFoodFlavor* B);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "AddEqual", CompactNodeTitle = "+=", Keywords = "+= add addequal plusequal"), Category = "HiveFeast")
	static void AddEqualFoodFlavor(UFoodFlavor* Source,UFoodFlavor* Other);
};
