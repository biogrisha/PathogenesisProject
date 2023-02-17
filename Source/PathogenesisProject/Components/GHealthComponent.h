// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GHealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);

class IGHealthWidget;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PATHOGENESISPROJECT_API UGHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGHealthComponent();

	UFUNCTION(BlueprintCallable)
	void Heal(float Value);

	//Set widget to display health percent
	UFUNCTION(BlueprintCallable)
	void SetWidget(const TScriptInterface<IGHealthWidget>& InWidget);

	UFUNCTION(BlueprintCallable)
	void SetHealth(float Value);

	UFUNCTION(BlueprintCallable,BlueprintPure)
	FORCEINLINE float GetHealth(){return Health;}
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UFUNCTION(Category = "Health")
	void ApplyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
	
	UPROPERTY(Category = "Health",BlueprintSetter=SetHealth,BlueprintGetter=GetHealth)
	float Health;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Health")
	float DefaultHealth = 100;

	UPROPERTY()
	TScriptInterface<IGHealthWidget> Widget;

	//Being called when HP is zero
	UPROPERTY(BlueprintAssignable)
	FOnDeath OnDeath;
	

		
		
};
