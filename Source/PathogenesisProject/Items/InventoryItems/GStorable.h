// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GStorable.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable,MinimalAPI)
class UGStorable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PATHOGENESISPROJECT_API IGStorable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	/**
	 * Create and return UGInventoryItemBase to store in UGInventoryComponent
	 *
	 * Must create, store in implementing object and return UGInventoryItemBase. Dont forget to call UGInventoryItem_::Init
	 *
	 * @param Outer Outer object must be Actor that uses inventory or InventoryComponent itself, because IGStorable will be Destroyed
	 * in case it is being collected.
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	class UGInventoryItemBase* GetItemInventoryData(UObject* Outer);

	//Write current object state to UGInventoryItemBase
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void UpdateItemInventoryData();

	//Initialize object's properties from UGInventoryItemBase object and it's PrimaryDataAsset
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void InitFromItemData(UGInventoryItemBase* Data);

	//Unload objects Primary Data Asset (here we're talking about IGStorable object, not UGInventoryItemBase)
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void UnloadAssets();

	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	bool IsLoaded();

private:
	
};
