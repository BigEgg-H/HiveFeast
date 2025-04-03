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
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "HiveFeast")
	static UFoodFlavor* CreateFoodFlavor(TMap<EFlavorType,double> SourceData);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Add", CompactNodeTitle = "+", Keywords = "+ add plus"), Category = "HiveFeast")
	static UFoodFlavor* AddFoodFlavor(UFoodFlavor* A,UFoodFlavor* B);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "AddEqual", CompactNodeTitle = "+=", Keywords = "+= add addequal plusequal"), Category = "HiveFeast")
	static void AddEqualFoodFlavor(UFoodFlavor* Source,UFoodFlavor* Other);
};
