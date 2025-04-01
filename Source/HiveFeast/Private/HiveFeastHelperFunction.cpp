// Fill out your copyright notice in the Description page of Project Settings.


#include "HiveFeastHelperFunction.h"


double UHiveFeastHelperFunction::ComprehensiveScore(TSet<AFood*> SourceFood)
{
	FFlavorWeight AverageWeight = {
		1,1,1,1,
		1,1,1,1,
		1,1,1,1,
		1,1,1,1,
		1,1
	};
	
	return ComprehensiveScoreByWeight(SourceFood,AverageWeight);
}

double UHiveFeastHelperFunction::ComprehensiveScoreByWeight(TSet<AFood*> SourceFood, FFlavorWeight Weight)
{
	return 0.0;
}

UFoodFlavor* UHiveFeastHelperFunction::AddFoodFlavor(UFoodFlavor* A, UFoodFlavor* B)
{
	return A->operator+(B);
}

void UHiveFeastHelperFunction::AddEqualFoodFlavor(UFoodFlavor* Source, UFoodFlavor* Other)
{
	Source->operator+=(Other);
}
