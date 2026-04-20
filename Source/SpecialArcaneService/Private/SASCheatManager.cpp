// Fill out your copyright notice in the Description page of Project Settings.


#include "SASCheatManager.h"

USASCheatManager::USASCheatManager() {
    
    if(nullptr == GetWorld()) {
        return;
    }
    
    TArray<AActor*> found;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASASGameMode::StaticClass(), found);
    AActor* found_mode = found.Num() > 0 ? found[0] : nullptr;
    gameModeRef = Cast<ASASGameMode>(found_mode);
    
    IConsoleCommand* GodModeEnable = IConsoleManager::Get().RegisterConsoleCommand(
        TEXT("sv_immortal"),
        TEXT("Make the player unkillable"),
        FConsoleCommandDelegate::CreateUObject(this, &USASCheatManager::Immortal),
        ECVF_Cheat
    );
    
}

void USASCheatManager::Immortal() {
    gameModeRef->Server_Immortal = true;
    UE_LOG(LogTemp, Display, TEXT("Server Immortal"));
}
