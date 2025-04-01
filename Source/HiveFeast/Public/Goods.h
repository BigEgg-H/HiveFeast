// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HiveFeast/Public/FoodBase.h"
#include "Goods.generated.h"

/*所有货物的基类,储存了货物具有的共同成员函数和变量.*/
UCLASS()
class HIVEFEAST_API AGoods : public AActor
{
	GENERATED_BODY()
	
public:	
	AGoods();

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="HiveFeast|Goods")
	UStaticMesh* GoodsStaticMesh;

};
