// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "../../DataAssets/GGunDataAsset.h"
#include "../InventoryItems/GStorable.h"
#include "CoreMinimal.h"
#include "GAmmoBase.h"
#include "GPickableBase.h"
#include "GWeaponBase.generated.h"

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAmmoUpdated, int32, Ammo);


UCLASS()
class PATHOGENESISPROJECT_API AGWeaponBase : public AGPickableBase,public IGStorable
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	void InitPropertiesFromDataAsset(UGGunDataAsset* Asset);

	UPROPERTY(BlueprintReadOnly,VisibleAnywhere)
	int32 MagazineCapacity;

	UPROPERTY(BlueprintReadOnly,VisibleAnywhere)
	int32 CurrentMagazine;
	
	UPROPERTY(BlueprintReadOnly,VisibleAnywhere)
	EAmmoType WeaponAmmoType;

	UPROPERTY(BlueprintReadOnly,VisibleAnywhere)
	float WeaponDamage;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TSoftObjectPtr<UGGunDataAsset> DataAsset;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	UClass* ObjectClass;
public:

	//Returns remainder of ammo and replenish ammo in the weapon
	UFUNCTION(BlueprintCallable)
	int32 Reload(int32 CurrentAmmo);
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	void Shoot(const FVector& Target,AActor* Shooter);
	
	UFUNCTION(BlueprintCallable)
	void SetCurrentMagazine(int32 Num);

	UFUNCTION(BlueprintCallable)
	FORCEINLINE float GetWeaponDamage() const { return WeaponDamage; }

	virtual UGInventoryItemBase* GetItemInventoryData_Implementation(UObject* Outer)override;

	virtual void UpdateItemInventoryData_Implementation() override;
	virtual void InitFromItemData_Implementation(UGInventoryItemBase* Data)override;
	
	virtual void UnloadAssets_Implementation()override;
	virtual bool IsLoaded_Implementation() override;
protected:
	//Auxiliary function to load assets in BP 
	UFUNCTION(BlueprintNativeEvent)
	void InitFromItemDataBP(UGInventoryItemBase* Data);

	//Auxiliary function to unload assets in BP 
	UFUNCTION(BlueprintNativeEvent)
	void UnloadAssetsBP();

	UPROPERTY()
	class UGInventoryItemMainWeapon* ItemInventoryData;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	bool bIsShooting;

	bool bIsAssetLoaded = false;

	UPROPERTY(BlueprintAssignable)
	FAmmoUpdated AmmoUpdated;
	
};
