// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PathogenesisProject/Items/Pickable/GAmmoBase.h"
#include "GGunDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class PATHOGENESISPROJECT_API UGGunDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Properties")
	int32 MagazineCapacity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Properties")
	int32 CurrentMagazine;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Properties")
	EAmmoType WeaponAmmoType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Properties")
	float WeaponDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Properties")
	FString Name;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Visual" , meta = (AssetBundles = "Game"))
	TSoftObjectPtr<USkeletalMesh> Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Visual",meta = (AssetBundles = "Game"))
	TSoftObjectPtr<UAnimSequence> Animation;

	FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId(PrimaryAssetType, GetFName());
	}


	const static FName PrimaryAssetType;

};
