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

UFoodFlavor* UFoodFlavor::operator+(const UFoodFlavor* Other) const
{
	//TODO:Finish + operator
	UFoodFlavor* Buffer = NewObject<UFoodFlavor>();
	return Buffer;
}

void UFoodFlavor::operator+=(const UFoodFlavor* Other)
{
	//TODO:Finish += operator
	Data = Other->Data;
}

const TMap<EFlavorType, double>* UFoodFlavor::GetDataPtr() const
{
	return &Data;
}
