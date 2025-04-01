// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FoodFlavor.generated.h"

/*枚举出了食物风味中所有"色"属性的标签*/
UENUM(BlueprintType, Category = "HiveFeast|Food|Flavor")
enum class EFoodColor : uint8
{
	None UMETA(DisplayName = "None"),
	Colorful UMETA(DisplayName = "Colorful"),
	Eastern UMETA(DisplayName = "Eastern"),
	Western UMETA(DisplayName = "Western"),
	Luxury UMETA(DisplayName = "Luxury"),
	Simple UMETA(DisplayName = "Simple"),
};
#define NUM_OF_FOOD_COLORS 5

/*枚举出了食物风味中所有"香"属性的标签*/
UENUM(BlueprintType, Category = "HiveFeast|Food|Flavor")
enum class EFoodAroma : uint8
{
	None UMETA(DisplayName = "None"),
	Foul UMETA(DisplayName = "Foul"),
	Fishy UMETA(DisplayName = "Fishy"),
	Burnt UMETA(DisplayName = "Burnt"),
	Fragrant UMETA(DisplayName = "Fragrant"),
	Rotten UMETA(DisplayName = "Rotten"),
};
#define NUM_OF_FOOD_AROMA 5

/*枚举出了食物风味中所有"味"属性的标签*/
UENUM(BlueprintType, Category = "HiveFeast|Food|Flavor")
enum class EFoodTaste : uint8
{
	None UMETA(DisplayName = "None"),
	Sour UMETA(DisplayName = "Sour"),
	Sweet UMETA(DisplayName = "Sweet"),
	Bitter UMETA(DisplayName = "Bitter"),
	Hot UMETA(DisplayName = "Hot"),
	Salty UMETA(DisplayName = "Salty"),
	Astringent UMETA(DisplayName = "Astringent"),
	Fresh UMETA(DisplayName = "Fresh"),
	OverCooked UMETA(DisplayName = "OverCooked"),
};
#define NUM_OF_FOOD_TASTE 8

/*用来储存口味偏好权重的结构体.包含了对象对每个口味的权重,范围应该设计在-1~1之间.*/
USTRUCT(BlueprintType, Category = "HiveFeast|Food|Flavor")
struct FFlavorWeight
{
	GENERATED_BODY()

	/*对食物"色"的"彩色"标签的权重(-1到1的范围)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast|Food|Flavor")
	double Color_Weight_Colorful = 0.0;
	/*对食物"色"的"东方"标签的权重(-1到1的范围)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast|Food|Flavor")
	double Color_Weight_Eastern= 0.0;
	/*对食物"色"的"西方"标签的权重(-1到1的范围)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast|Food|Flavor")
	double Color_Weight_Western= 0.0;
	/*对食物"色"的"豪华"标签的权重(-1到1的范围)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast|Food|Flavor")
	double Color_Weight_Luxury= 0.0;
	/*对食物"色"的"简约"标签的权重(-1到1的范围)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast|Food|Flavor")
	double Color_Weight_Simple= 0.0;

	double GetWeightColor(EFoodColor Target) const
	{
		switch (Target)
		{
		case EFoodColor::Colorful:
			return Color_Weight_Colorful;
		case EFoodColor::Eastern:
			return Color_Weight_Eastern;
		case EFoodColor::Western:
			return Color_Weight_Western;
		case EFoodColor::Luxury:
			return Color_Weight_Luxury;
		case EFoodColor::Simple:
			return Color_Weight_Simple;
		default:
			return 0.0;
		}
	}
	
	/*对食物"香"的"骚臭"标签的权重(-1到1的范围)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast|Food|Flavor")
	double Aroma_Weight_Foul= 0.0;
	/*对食物"香"的"腥臭"标签的权重(-1到1的范围)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast|Food|Flavor")
	double Aroma_Weight_Fishy= 0.0;
	/*对食物"香"的"烧焦"标签的权重(-1到1的范围)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast|Food|Flavor")
	double Aroma_Weight_Burnt= 0.0;
	/*对食物"香"的"鲜香"标签的权重(-1到1的范围)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast|Food|Flavor")
	double Aroma_Weight_Fragrant= 0.0;
	/*对食物"香"的"腐臭"标签的权重(-1到1的范围)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast|Food|Flavor")
	double Aroma_Weight_Rotten= 0.0;

	double GetWeightAroma(EFoodAroma Target) const
	{
		switch (Target)
		{
		case EFoodAroma::Foul:
			return Aroma_Weight_Foul;
		case EFoodAroma::Fishy:
			return Aroma_Weight_Fishy;
		case EFoodAroma::Burnt:
			return Aroma_Weight_Burnt;
		case EFoodAroma::Fragrant:
			return Aroma_Weight_Fragrant;
		case EFoodAroma::Rotten:
			return Aroma_Weight_Rotten;
		default:
			return 0.0;
		}
	}
	
	/*对食物"味"的"酸"标签的权重(-1到1的范围)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast|Food|Flavor")
	double Taste_Weight_Sour= 0.0;
	/*对食物"味"的"甜"标签的权重(-1到1的范围)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast|Food|Flavor")
	double Taste_Weight_Sweet= 0.0;
	/*对食物"味"的"苦"标签的权重(-1到1的范围)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast|Food|Flavor")
	double Taste_Weight_Bitter= 0.0;
	/*对食物"味"的"辣"标签的权重(-1到1的范围)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast|Food|Flavor")
	double Taste_Weight_Hot= 0.0;
	/*对食物"味"的"咸"标签的权重(-1到1的范围)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast|Food|Flavor")
	double Taste_Weight_Salty= 0.0;
	/*对食物"味"的"甘"标签的权重(-1到1的范围)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast|Food|Flavor")
	double Taste_Weight_Astringent= 0.0;
	/*对食物"味"的"鲜"标签的权重(-1到1的范围)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast|Food|Flavor")
	double Taste_Weight_Fresh= 0.0;
	/*对食物"味"的"焦"标签的权重(-1到1的范围)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast|Food|Flavor")
	double Taste_Weight_OverCooked= 0.0;

	double GetWeightTaste(EFoodTaste Target) const
	{
		switch (Target)
		{
		case EFoodTaste::Sour:
			return Taste_Weight_Sour;
		case EFoodTaste::Sweet:
			return Taste_Weight_Sweet;
		case EFoodTaste::Bitter:
			return Taste_Weight_Bitter;
		case EFoodTaste::Hot:
			return Taste_Weight_Hot;
		case EFoodTaste::Salty:
			return Taste_Weight_Salty;
		case EFoodTaste::Astringent:
			return Taste_Weight_Astringent;
		case EFoodTaste::Fresh:
			return Taste_Weight_Fresh;
		case EFoodTaste::OverCooked:
			return Taste_Weight_OverCooked;
		default:
			return 0.0;
		}
	}
	
};

UENUM(BlueprintType, Category = "HiveFeast")
enum class EFlavorType : uint8
{
	None = 0 UMETA(DisplayName = "None"),
	Colorful UMETA(DisplayName = "Colorful"),
	Eastern UMETA(DisplayName = "Eastern"),
	Western UMETA(DisplayName = "Western"),
	Luxury UMETA(DisplayName = "Luxury"),
	Simple UMETA(DisplayName = "Simple"),
	Foul UMETA(DisplayName = "Foul"),
	Fishy UMETA(DisplayName = "Fishy"),
	Burnt UMETA(DisplayName = "Burnt"),
	Fragrant UMETA(DisplayName = "Fragrant"),
	Rotten UMETA(DisplayName = "Rotten"),
	Sour UMETA(DisplayName = "Sour"),
	Sweet UMETA(DisplayName = "Sweet"),
	Bitter UMETA(DisplayName = "Bitter"),
	Hot UMETA(DisplayName = "Hot"),
	Salty UMETA(DisplayName = "Salty"),
	Astringent UMETA(DisplayName = "Astringent"),
	Fresh UMETA(DisplayName = "Fresh"),
	OverCooked UMETA(DisplayName = "OverCooked"),
};
#define HV_NUM_OF_FLAVOR_TYPE 19

UCLASS(BlueprintType, Category = "HiveFeast")
class HIVEFEAST_API UFoodFlavor : public UObject
{
	GENERATED_BODY()
	
public:
	UFoodFlavor();

	UFUNCTION(BlueprintCallable, Category = "HiveFeast")
	double GetScore(EFlavorType TargetType);

	UFUNCTION(BlueprintCallable, Category = "HiveFeast")
	TMap<EFlavorType,double> CopyAllScore();

	UFUNCTION(BlueprintCallable, Category = "HiveFeast")
	void SetScore(EFlavorType TargetType, double TargetScore);

	UFoodFlavor* operator+(const UFoodFlavor* Other) const;

	void operator+=(const UFoodFlavor* Other);
	
	const TMap<EFlavorType,double>* GetDataPtr() const;

private:
	UPROPERTY()
	TMap<EFlavorType,double> Data;
};
