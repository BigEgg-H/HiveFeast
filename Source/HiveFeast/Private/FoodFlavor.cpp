// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodFlavor.h"

UFoodFlavor::UFoodFlavor()
{
	Data.Reserve(HV_NUM_OF_FLAVOR_TYPE);
}

double UFoodFlavor::GetScore(EFlavorType TargetType)
{
	if (Data.Contains(TargetType))
	{
		return Data[TargetType];
	}
	return 0.0;
}

TMap<EFlavorType, double> UFoodFlavor::CopyAllScore()
{
	return Data;
}

void UFoodFlavor::SetScore(EFlavorType TargetType, double TargetScore)
{
	Data.Add(TargetType, TargetScore);
}

double UFoodFlavor::ComprehensiveScoreByWeight(FFlavorWeight Weight)
{
	//TODO: Comprehensive Score By Weight
	
	return 0;
}

double UFoodFlavor::ComprehensiveScore()
{
	//TODO: Comprehensive Score
	
	return 0;
}

UFoodFlavor* UFoodFlavor::operator+(const UFoodFlavor* Other) const
{
	UFoodFlavor* Buffer = NewObject<UFoodFlavor>();
	//TODO:Finish + operator
	
	return Buffer;
}

void UFoodFlavor::operator+=(const UFoodFlavor* Other)
{
	//TODO:Finish += operator
	
}

void UFoodFlavor::operator*=(double Other)
{
	//TODO:Finish *= operator
	
}

UFoodFlavor* UFoodFlavor::operator*(double Other) const
{
	UFoodFlavor* Buffer = NewObject<UFoodFlavor>();
	//TODO:Finish * operator
	
	return Buffer;
}

const TMap<EFlavorType, double>* UFoodFlavor::GetDataPtr() const
{
	return &Data;
}

void UFoodFlavor::SetData(const TMap<EFlavorType, double>& SourceData)
{
	Data = SourceData;
}
