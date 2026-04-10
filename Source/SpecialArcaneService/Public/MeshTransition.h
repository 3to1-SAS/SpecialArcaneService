// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MeshTransition.generated.h"

/**
 * 
 */
UCLASS()
class SPECIALARCANESERVICE_API UMeshTransition : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category = "UMeshTransition")
    static TArray<int32> ATriangleIndices(UStaticMeshComponent* MeshComponent, int32 MaterialSlotIndex, int32 LODIndex);
};
