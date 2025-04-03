// Fill out your copyright notice in the Description page of Project Settings.


#include "HiveFeastHelperFunction.h"

UFoodFlavor* UHiveFeastHelperFunction::CreateFoodFlavor(TMap<EFlavorType, double> SourceData)
{
	UFoodFlavor* Buffer = NewObject<UFoodFlavor>();
	Buffer->SetData(SourceData);
	return Buffer;
}

UFoodFlavor* UHiveFeastHelperFunction::AddFoodFlavor(UFoodFlavor* A, UFoodFlavor* B)
{
	return A->operator+(B);
}

void UHiveFeastHelperFunction::AddEqualFoodFlavor(UFoodFlavor* Source, UFoodFlavor* Other)
{
	Source->operator+=(Other);
}
