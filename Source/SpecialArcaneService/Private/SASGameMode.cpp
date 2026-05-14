// Fill out your copyright notice in the Description page of Project Settings.


#include "SASGameMode.h"

ASASGameMode::ASASGameMode() {
    
    if(nullptr == GetWorld())
    {
        return;
    }
    
    IConsoleManager::Get().RegisterConsoleCommand(
        TEXT("sas_cheat"),
        TEXT("Allows cheats in game"),
        FConsoleCommandDelegate::CreateUObject(this, &ASASGameMode::ccmd_cheats_enable),
        ECVF_Cheat
    );
    
    IConsoleManager::Get().RegisterConsoleCommand(
        TEXT("cheddar"),
        TEXT("spawns tristan's cheese"),
        FConsoleCommandDelegate::CreateUObject(this, &ASASGameMode::ccmd_cheats_cheese),
        ECVF_Cheat
    );
    
    IConsoleManager::Get().RegisterConsoleCommand(
        TEXT("michaeltransaction"),
        TEXT("makes the player move at a tolerable speed + enabes jumping, also spawns a cantelope"),
        FConsoleCommandDelegate::CreateUObject(this, &ASASGameMode::ccmd_cheats_michael),
        ECVF_Cheat
    );
    
    IConsoleManager::Get().RegisterConsoleCommand(
        TEXT("sas_immortal"),
        TEXT("take no moar damage"),
        FConsoleCommandDelegate::CreateUObject(this, &ASASGameMode::ccmd_cheats_immortal),
        ECVF_Cheat
    );
}


void ASASGameMode::ccmd_cheats_enable() {
    if(cheats_enabled) {
        cheats_enabled = false;
        UE_LOG(LogTemp, Display, TEXT("CHEATS DISABLED"));
        return;
    }
    cheats_enabled = true;
    UE_LOG(LogTemp, Display, TEXT("CHEATS ENABLED"));
}

void ASASGameMode::ccmd_cheats_cheese() {
    if(cheats_enabled) {
        if(!cheat_cheese) {
            cheat_cheese = true;
        } else {
            cheat_cheese = false;
        }
    }
}

void ASASGameMode::ccmd_cheats_immortal() {
    if(cheats_enabled) {
        if(!cheat_immortal) {
            cheat_immortal = true;
        } else {
            cheat_immortal = false;
        }
    }
}

void ASASGameMode::ccmd_cheats_michael() {
    if(cheats_enabled) {
        if(!cheat_michael) {
            cheat_michael = true;
        } else {
            cheat_michael = false;
        }
    }
}
