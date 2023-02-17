// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GPickableBase.h"
#include "GAmmoBase.generated.h"

UENUM(BlueprintType)
enum class EAmmoType : uint8
{
	RiffleAmmo,
	PistolAmmo,
};

UCLASS()
class PATHOGENESISPROJECT_API AGAmmoBase : public AGPickableBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	EAmmoType AmmoType;

	UPROPERTY(EditDefaultsOnly)
	int32 Count;
public:
	UFUNCTION(BlueprintCallable)
	FORCEINLINE EAmmoType GetAmmoType() const { return AmmoType; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32 GetAmmoCount() const { return Count; }
};
