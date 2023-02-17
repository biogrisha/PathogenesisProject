// Fill out your copyright notice in the Description page of Project Settings.


#include "GSaveDataProxy.h"

FDataToSave UGSaveDataProxy::GetData()
{
	return SaveData;
}

void UGSaveDataProxy::SetData(const FDataToSave& Data)
{
	SaveData = Data;
}

void UGSaveDataProxy::SetStoredObjectName(const FString& Name)
{
	ObjectName = Name;
}

FString UGSaveDataProxy::GetStoredObjectName()
{
	return ObjectName;
}
