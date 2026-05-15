// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "SASGameMode.generated.h"

UCLASS()
class SPECIALARCANESERVICE_API ASASGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    void ccmd_cheats_enable();
    UFUNCTION(BlueprintCallable)
    void ccmd_cheats_cheese();
    UFUNCTION(BlueprintCallable)
    void ccmd_cheats_immortal();
    UFUNCTION(BlueprintCallable)
    void ccmd_cheats_michael();
    
    ASASGameMode();
	
protected:
    bool cheats_enabled;
    bool cheat_michael;
    bool cheat_cheese;
    bool cheat_immortal;
};
