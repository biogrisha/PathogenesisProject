// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Pickable/EItemType.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GInventoryItemBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class PATHOGENESISPROJECT_API UGInventoryItemBase : public UObject
{
	GENERATED_BODY()

public:
	//Not virtual because called after creation with specified derived type. Don't forget to call Super::Init in derived Init function 
	void Init(const EItemType& InItemType);
	//Don't use it to access any data, performance only purpose
	FORCEINLINE uint32  GetIdInInventoryArray()const{return IdInInventoryArray; }
	//Don't use it to access any data, performance only purpose
	FORCEINLINE void SetIdInInventoryArray(uint32 InIdInInventory)const{IdInInventoryArray = InIdInInventory;}

	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32 GetUniqueId(){return Id;}

	UFUNCTION(BlueprintCallable)
	FORCEINLINE EItemType GetItemType()const{return ItemType; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE UPrimaryDataAsset* GetDataAsset()const{return DataAsset.Get();}

	//
	/**
 	* Load Primary Data Asset in memory
 	*
 	* Must be called before accessing Primary Data Asset of Item
 	*
 	* @param Delegate Called after loading ended.
 	*/
	UFUNCTION(BlueprintCallable)
	void LoadDataAsset(UPARAM(DisplayName="Event") FTimerDynamicDelegate Delegate);

	//Unload and reset PrimaryDataAsset of Item 
	UFUNCTION(BlueprintCallable)
	void ResetItem();
	
	UFUNCTION(BlueprintCallable)
	bool IsAssetLoaded() const;
private:
	mutable uint32 IdInInventoryArray = 0;
	int32 Id = -1;
	void OnAssetLoaded(FTimerDynamicDelegate FinishDelegate);

	static uint32 GenerateUniqueId()
	{
		static uint32 IdStatic = 0;
		return IdStatic++;
	}
protected:
	//Must be set in derived classes using Super::Init
	EItemType ItemType = EItemType::Usable;
	
	TSoftObjectPtr<UPrimaryDataAsset> DataAsset;

	//Must be set in derived classes using Super::Init
	FPrimaryAssetId AssetId;

	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	UClass* ObjectClass;

	
};
