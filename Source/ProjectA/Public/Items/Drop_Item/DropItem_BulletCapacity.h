// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Drop_Item/ItemBase.h"
#include "DropItem_BulletCapacity.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTA_API ADropItem_BulletCapacity : public AItemBase
{
	GENERATED_BODY()

public:
	ADropItem_BulletCapacity();

protected:
	virtual void BeginPlay() override;

	int32 Item_Type;


public:
	virtual void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	virtual void SetItemMesh(int32 Type) override;
};
