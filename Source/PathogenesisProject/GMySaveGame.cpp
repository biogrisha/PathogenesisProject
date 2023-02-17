// Fill out your copyright notice in the Description page of Project Settings.


#include "GMySaveGame.h"

void UGMySaveGame::UpdateData(const FDataToSave& Data, const FString& ObjectName)
{
	DataMap.Add(ObjectName,Data);
}

bool UGMySaveGame::LoadData(const FString& ObjectName, FDataToSave& OutData)
{
	bool KeyExists = false;
	FDataToSave* DataTemp = DataMap.Find(ObjectName);
	if(DataTemp)
	{
		OutData = *DataTemp;
		KeyExists = true;
	}
	return KeyExists;
}

void UGMySaveGame::ClearSaveData()
{
	DataMap.Empty();
}
