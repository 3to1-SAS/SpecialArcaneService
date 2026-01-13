// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryPlusPlus.h"

UInventoryPlusPlus::UInventoryPlusPlus() {
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UInventoryPlusPlus::BeginPlay() {
	Super::BeginPlay();
    
}

/*
// Called every frame
void UInventoryPlusPlus::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
*/
