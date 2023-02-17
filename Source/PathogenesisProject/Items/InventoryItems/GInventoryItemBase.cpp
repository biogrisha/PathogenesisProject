// Fill out your copyright notice in the Description page of Project Settings.


#include "GInventoryItemBase.h"

#include "Engine/AssetManager.h"

void UGInventoryItemBase::Init(const EItemType& InItemType)
{
	Id = GenerateUniqueId();
	ItemType = InItemType;
}

void UGInventoryItemBase::LoadDataAsset(FTimerDynamicDelegate FinishDelegate)
{
	if(AssetId.IsValid())
	{
		if(UAssetManager* Manager = UAssetManager::GetIfValid())
		{
			TArray<FName> Bundles;
			FStreamableDelegate Delegate = FStreamableDelegate::CreateUObject(this, &UGInventoryItemBase::OnAssetLoaded,FinishDelegate);
			Manager->LoadPrimaryAsset(AssetId, Bundles, Delegate);
		}
	}
}

void UGInventoryItemBase::ResetItem()
{
	if(UAssetManager* Manager = UAssetManager::GetIfValid())
	{
		Manager->UnloadPrimaryAsset(DataAsset->GetPrimaryAssetId());
		DataAsset.Reset();
	}
}

bool UGInventoryItemBase::IsAssetLoaded() const
{
	return !DataAsset.IsNull();
}

void UGInventoryItemBase::OnAssetLoaded(FTimerDynamicDelegate FinishDelegate)
{
	if(UAssetManager* Manager = UAssetManager::GetIfValid())
	{
		DataAsset = Manager->GetPrimaryAssetObject(AssetId);
		FinishDelegate.ExecuteIfBound();
	}
}
