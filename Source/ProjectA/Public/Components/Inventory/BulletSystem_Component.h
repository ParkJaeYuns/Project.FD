// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BulletSystem_Component.generated.h"

class UInventory_Component;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTA_API UBulletSystem_Component : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBulletSystem_Component();

	UInventory_Component* InventoryComponent;

	
	UFUNCTION(BlueprintCallable, Category = "UsedBullet")
	bool TryUseBullet_AR();

	UFUNCTION(BlueprintCallable, Category = "Reload")
	bool TryReloadBullet_AR();

	UFUNCTION(BlueprintCallable, Category = "UsedBullet")
	bool TryUseBullet_DMR();

	UFUNCTION(BlueprintCallable, Category = "Reload")
	bool TryReloadBullet_DMR();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame

private:



		
};
