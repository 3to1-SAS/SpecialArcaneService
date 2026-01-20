// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryPlusPlus.h"

UInventoryPlusPlus::UInventoryPlusPlus() {
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UInventoryPlusPlus::BeginPlay() {
	Super::BeginPlay();
    
    Cast<> UGameplayStatistics::LoadGameFromSlot(TEXT("UserSaveData"), 0);
    
}

void UInventoryPlusPlus::AddItem(short where) {
    return;
}

void UInventoryPlusPlus::DeleteItem(short index) {
    return;
}

void UInventoryPlusPlus::PickupItem(AActor* actor) {
    
}

/*
// Called every frame
void UInventoryPlusPlus::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
*/
