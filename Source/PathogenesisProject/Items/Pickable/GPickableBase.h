// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EItemType.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GPickableBase.generated.h"

USTRUCT(BlueprintType)
struct FPickableItemData
{
	GENERATED_BODY()

	EItemType ItemType = EItemType::Usable;
};

UCLASS()
class PATHOGENESISPROJECT_API AGPickableBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AGPickableBase();

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	EItemType ItemType = EItemType::Usable;
	
public:
	UFUNCTION(BlueprintCallable)
	FORCEINLINE EItemType GetType() const { return ItemType; }
};
