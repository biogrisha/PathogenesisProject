// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Interfaces/GInventoryWidget.h"
#include"../Items/InventoryItems/GInventoryItemBase.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GInventoryComponent.generated.h"

/*
 * Accepts UGInventoryItemBase as an Item data storage that you can receive from an object which class implements IGStorable
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PATHOGENESISPROJECT_API UGInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	void AddItem(UGInventoryItemBase* Item);

	UFUNCTION(BlueprintCallable)
	void RemoveItem(UGInventoryItemBase* Item);
	
	UFUNCTION(BlueprintCallable)
	UGInventoryItemBase* GetItemById(int32 Id);

	//Set Widget to display inventory 
	UFUNCTION(BlueprintCallable)
	void SetWidget(const TScriptInterface<IGInventoryWidget>& InWidget);
	
	UFUNCTION(BlueprintCallable)
	void SetItemToSlot(UGInventoryItemBase* Item,int32 Num);
protected:

	UPROPERTY()
	TArray<UGInventoryItemBase*> Items;

	UPROPERTY()
	TScriptInterface<IGInventoryWidget> Widget;

	UPROPERTY()
	TArray<UGInventoryItemBase*> ItemsInSlots;
	
	UPROPERTY(EditAnywhere)
	int32 NumberOfSlots;
};
