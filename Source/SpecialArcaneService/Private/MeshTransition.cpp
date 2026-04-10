// Fill out your copyright notice in the Description page of Project Settings.


#include "MeshTransition.h"
#include "Engine/StaticMesh.h"
#include "Rendering/SkeletalMeshRenderData.h"

TArray<int32> UMeshTransition::ATriangleIndices(UStaticMeshComponent* MeshComponent, int32 MaterialSlotIndex, int32 LODIndex)
{
    TArray<int32> Triangles;
    
    if (UStaticMeshComponent* StaticMeshComponent = Cast<UStaticMeshComponent>(MeshComponent))
    {
        if(UStaticMesh* StaticMesh = StaticMeshComponent->GetStaticMesh())
        {
            if (StaticMesh->GetRenderData() && StaticMesh-> GetRenderData()->LODResources.IsValidIndex(LODIndex))
            {
                FStaticMeshLODResources& LOD = StaticMesh->GetRenderData()->LODResources[LODIndex];
                for(const FStaticMeshSection& Section : LOD.Sections)
                {
                    if (Section.MaterialIndex == MaterialSlotIndex)
                    {
                        for(uint32 TriangleIndex = 0; TriangleIndex < Section.NumTriangles; ++TriangleIndex)
                        {
                            Triangles.Add(Section.FirstIndex / 3 + TriangleIndex);
                        }
                    }
                }
            }
        }
    }
    
    return Triangles;
}
