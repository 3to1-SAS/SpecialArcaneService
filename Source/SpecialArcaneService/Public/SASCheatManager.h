// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "Kismet/GameplayStatics.h"
#include "SASGameMode.h"
#include "SASCheatManager.generated.h"

/**
 * 
 */
UCLASS()
class SPECIALARCANESERVICE_API USASCheatManager : public UCheatManager
{
	GENERATED_BODY()
public:
    ASASGameMode* gameModeRef;
    USASCheatManager();
    void Immortal();
};
