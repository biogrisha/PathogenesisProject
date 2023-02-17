// Fill out your copyright notice in the Description page of Project Settings.


#include "GInventoryComponent.h"

// Sets default values for this component's properties
UGInventoryComponent::UGInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UGInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	ItemsInSlots.Init(nullptr,2);
	NumberOfSlots = 2;
}

void UGInventoryComponent::AddItem(UGInventoryItemBase* Item)
{
	Item->SetIdInInventoryArray(Items.Num());
	Items.Add(Item);
	if(Widget.GetObject())
	{
		Widget->Execute_AddItem(Widget.GetObject(),Item);
	}
}

void UGInventoryComponent::RemoveItem(UGInventoryItemBase* Item)
{
	UGInventoryItemBase* Last = Items.Top();
	Last->SetIdInInventoryArray(Item->GetIdInInventoryArray());
	Items.Swap(Item->GetIdInInventoryArray(),Items.Num()-1);
	Items.Pop();
}

UGInventoryItemBase* UGInventoryComponent::GetItemById(int32 Id)
{
	return Items[Id];
}

void UGInventoryComponent::SetWidget(const TScriptInterface<IGInventoryWidget>& InWidget)
{
	Widget = InWidget;
}

void UGInventoryComponent::SetItemToSlot(UGInventoryItemBase* Item, int32 Num)
{
	if(Num<NumberOfSlots && Num >=0)
	{
		ItemsInSlots[Num] = Item;
		Widget->Execute_SetItemToSlot(Widget.GetObject(),Item,Num);
	}
}




