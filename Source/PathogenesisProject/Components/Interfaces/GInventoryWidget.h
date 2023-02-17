// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GInventoryWidget.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable,MinimalAPI)
class UGInventoryWidget : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PATHOGENESISPROJECT_API IGInventoryWidget
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void AddItem(class UGInventoryItemBase* Item);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetItemToSlot(class UGInventoryItemBase* Item,int32 Number);

};
