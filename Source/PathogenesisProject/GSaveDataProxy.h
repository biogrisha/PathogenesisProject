// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GMySaveGame.h"
#include "UObject/NoExportTypes.h"
#include "GSaveDataProxy.generated.h"

/**
 * This object must be created by Actor which want it's data to be saved
 * Needed to avoid coupling actor classes and GameMode class 
 */
UCLASS(Blueprintable)
class PATHOGENESISPROJECT_API UGSaveDataProxy : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	FDataToSave GetData();

	UFUNCTION(BlueprintCallable)
	void SetData(const FDataToSave& Data);

	UFUNCTION(BlueprintCallable)
	void SetStoredObjectName(const FString& Name);

	UFUNCTION(BlueprintCallable)
	FString GetStoredObjectName();
private:
	FDataToSave SaveData;
	FString ObjectName;
};
