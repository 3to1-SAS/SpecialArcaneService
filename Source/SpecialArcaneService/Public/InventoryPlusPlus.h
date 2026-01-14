// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
//#include "Blueprint/UserWidget.h"
#include <vector>
#include <unordered_map>
#include "InventoryPlusPlus.generated.h"

// typedefs

typedef unsigned short Uint16;

typedef struct {
    int x, y;
} Positional;

typedef struct {
    Positional pos;
    AActor* type;
    short index;
    Uint16 quantity;
} Item;

// Classdef
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPECIALARCANESERVICE_API UInventoryPlusPlus : public UActorComponent {
	GENERATED_BODY()
public:
    std::unordered_map<int, AActor*>    table;
    std::vector<UUserWidget*>           tableSlots;
    int invW, invH, invTS;
    
	UInventoryPlusPlus();
    // virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    virtual void AddItem(short where);
    virtual void DeleteItem(short index);
    
protected:
	virtual void BeginPlay() override;
};
