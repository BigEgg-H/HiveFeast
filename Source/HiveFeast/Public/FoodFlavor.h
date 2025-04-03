// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FoodFlavor.generated.h"

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

USTRUCT(BlueprintType, Blueprintable, Category = "HiveFeast")
struct FFlavorWeight
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	double ColorfulWeight = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	double EasternWeight = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	double WesternWeight = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	double LuxuryWeight = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	double SimpleWeight = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	double FoulWeight = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	double FishyWeight = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	double BurntWeight = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	double FragrantWeight = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	double RottenWeight = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	double SourWeight = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	double SweetWeight = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	double BitterWeight = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	double HotWeight = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	double SaltyWeight = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	double AstringentWeight = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	double FreshWeight = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HiveFeast")
	double OverCookedWeight = 0.0;
	
};

UCLASS(BlueprintType, Blueprintable, Category = "HiveFeast")
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

	UFUNCTION(BlueprintCallable, Category = "HiveFeast")
	double ComprehensiveScoreByWeight(FFlavorWeight Weight);

	UFUNCTION(BlueprintCallable, Category = "HiveFeast")
	double ComprehensiveScore();
	
	UFoodFlavor* operator+(const UFoodFlavor* Other) const;

	void operator+=(const UFoodFlavor* Other);

	void operator*=(double Other);

	UFoodFlavor* operator*(double Other) const;
	
	const TMap<EFlavorType,double>* GetDataPtr() const;

	void SetData(const TMap<EFlavorType,double>& SourceData);
	
private:
	UPROPERTY()
	TMap<EFlavorType,double> Data;
};
