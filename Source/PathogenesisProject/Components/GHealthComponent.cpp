// Fill out your copyright notice in the Description page of Project Settings.


#include "GHealthComponent.h"

#include "Interfaces/GHealthWidget.h"

// Sets default values for this component's properties
UGHealthComponent::UGHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	AActor* Owner = GetOwner();
	if(Owner)
	{
		Owner->OnTakeAnyDamage.AddDynamic(this,&UGHealthComponent::ApplyDamage);
	}
}


// Called when the game starts
void UGHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	Health = DefaultHealth;
	
	
}

void UGHealthComponent::ApplyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser)
{
	Health = FMath::Clamp(Health-Damage,0.0f,DefaultHealth);
	if(Widget.GetObject())
	{
		float Percent = (Health/DefaultHealth);
		Widget->Execute_SetHealth(Widget.GetObject(),Percent);
	}
	if(Health==0 && OnDeath.IsBound())
	{
		OnDeath.Broadcast();
	}
	
}

void UGHealthComponent::Heal(float Value)
{
	Health = FMath::Clamp(Health+ Value,0.0f,DefaultHealth);
	if(Widget.GetObject())
	{
		float Percent = (Health/DefaultHealth);
		Widget->Execute_SetHealth(Widget.GetObject(),Percent);
	}
}

void UGHealthComponent::SetWidget(const TScriptInterface<IGHealthWidget>& InWidget)
{
	Widget = InWidget;
	if(Widget.GetObject())
	{
		float Percent = (Health/DefaultHealth);
		Widget->Execute_SetHealth(Widget.GetObject(),Percent);
	}
}

void UGHealthComponent::SetHealth(float Value)
{
	Health = Value;
	if(Widget.GetObject())
	{
		float Percent = (Health/DefaultHealth);
		Widget->Execute_SetHealth(Widget.GetObject(),Percent);
	}
	if(Health==0 && OnDeath.IsBound())
	{
		OnDeath.Broadcast();
	}
}


