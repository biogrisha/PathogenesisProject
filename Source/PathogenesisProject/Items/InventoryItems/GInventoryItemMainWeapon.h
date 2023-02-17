// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GInventoryItemBase.h"
#include "GInventoryItemMainWeapon.generated.h"

/**
 * 
 */
UCLASS()
class PATHOGENESISPROJECT_API UGInventoryItemMainWeapon : public UGInventoryItemBase
{
	GENERATED_BODY()

public:
	FORCEINLINE void Init(UClass* InObjectClass,const FString& InName,int32 InAmmoInMagazine,
		EItemType InType,const FPrimaryAssetId& PrimaryAssetId)
	{
		ObjectClass = InObjectClass;
		Name = InName;
		AmmoInMagazine = InAmmoInMagazine;
		AssetId = PrimaryAssetId;
		Super::Init(InType);
	}

	void UpdateProperties(int32 InAmmoInMagazine)
	{
		AmmoInMagazine = InAmmoInMagazine;
	}

	FORCEINLINE int32 GetAmmoInMagazine()const{return AmmoInMagazine;}
protected:
	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	FString Name;
	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	int32 AmmoInMagazine;
	
	
	
};





