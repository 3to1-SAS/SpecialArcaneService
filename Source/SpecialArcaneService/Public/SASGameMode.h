// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SASGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SPECIALARCANESERVICE_API ASASGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
    bool Server_Immortal;
};
