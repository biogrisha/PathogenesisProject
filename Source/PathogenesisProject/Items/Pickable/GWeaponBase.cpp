// Fill out your copyright notice in the Description page of Project Settings.

#include "GWeaponBase.h"
#include "PathogenesisProject/DataAssets/GGunDataAsset.h"
#include "../InventoryItems/GInventoryItemMainWeapon.h"
#include "Engine/AssetManager.h"


void AGWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	InitPropertiesFromDataAsset(DataAsset.Get());
	
	
}

void AGWeaponBase::InitPropertiesFromDataAsset(UGGunDataAsset* Asset)
{
	if(DataAsset.IsNull())
	{
		DataAsset = Asset;
	}
	if(!DataAsset.IsValid())
	{
		DataAsset = DataAsset.LoadSynchronous();
	}
	if(DataAsset)
	{
		CurrentMagazine = DataAsset->CurrentMagazine;
		MagazineCapacity = DataAsset->MagazineCapacity;
		WeaponDamage = DataAsset->WeaponDamage;
		WeaponAmmoType = DataAsset->WeaponAmmoType;
	}
	
}

int32 AGWeaponBase::Reload(int32 CurrentAmmo)
{
	const bool bCurrentAmmoEnough = CurrentAmmo >= MagazineCapacity;
	const uint32 CurrentAmmoTemp = CurrentAmmo;
	CurrentAmmo = FMath::Max(CurrentAmmo-MagazineCapacity,0);
	CurrentMagazine = bCurrentAmmoEnough*MagazineCapacity +
					(!bCurrentAmmoEnough)*CurrentAmmoTemp;
	return CurrentAmmo;
}

void AGWeaponBase::SetCurrentMagazine(int32 Num)
{
	CurrentMagazine = FMath::Clamp(Num,0, MagazineCapacity);
}

UGInventoryItemBase* AGWeaponBase::GetItemInventoryData_Implementation(UObject* Outer)
{
	if(!ItemInventoryData)
	{
		ItemInventoryData =
		NewObject<UGInventoryItemMainWeapon>(Outer,UGInventoryItemMainWeapon::StaticClass());

		if(ItemInventoryData && !DataAsset.IsNull())
		{
			ItemInventoryData->Init(ObjectClass,DataAsset->Name,CurrentMagazine,ItemType,DataAsset->GetPrimaryAssetId());
		}
	}
	
	return ItemInventoryData;
}

void AGWeaponBase::UpdateItemInventoryData_Implementation()
{
	ItemInventoryData->UpdateProperties(CurrentMagazine);
}

void AGWeaponBase::InitFromItemData_Implementation(UGInventoryItemBase* Data)
{
	ItemInventoryData = Cast<UGInventoryItemMainWeapon>(Data);
	auto Asset = Cast<UGGunDataAsset>(ItemInventoryData->GetDataAsset());
	InitPropertiesFromDataAsset(Asset);
	
	CurrentMagazine = ItemInventoryData->GetAmmoInMagazine();

	if(ItemInventoryData)
	{
		InitFromItemDataBP(Data);
	}
}

void AGWeaponBase::UnloadAssets_Implementation()
{

	UnloadAssetsBP();//Free components which use Assets data such as Mesh, Animation, etc.
	UAssetManager* Manager = UAssetManager::GetIfValid();
	if(Manager && !DataAsset.IsNull())
	{
		Manager->UnloadPrimaryAsset(DataAsset->GetPrimaryAssetId());
		DataAsset.Reset();
	}
}

void AGWeaponBase::UnloadAssetsBP_Implementation()
{
}

void AGWeaponBase::InitFromItemDataBP_Implementation(UGInventoryItemBase* Data)
{
}

void AGWeaponBase::Shoot_Implementation(const FVector& Target,AActor* Shooter)
{
}
