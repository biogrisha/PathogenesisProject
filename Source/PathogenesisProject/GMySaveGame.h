// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GMySaveGame.generated.h"

USTRUCT(BlueprintType)
struct FDataToSave
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	FVector Location;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	float Health = 0;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	bool IsAlive = false;
};

UCLASS()
class PATHOGENESISPROJECT_API UGMySaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void UpdateData(const FDataToSave& Data, const FString& ObjectName);

	UFUNCTION(BlueprintCallable)
	bool LoadData(const FString& ObjectName,FDataToSave& OutData);

	UFUNCTION(BlueprintCallable)
	void ClearSaveData();
private:
	UPROPERTY()
	TMap<FString,FDataToSave> DataMap;
};
