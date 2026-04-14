// Fill out your copyright notice in the Description page of Project Settings.


#include "MeshTransition.h"
#include "Engine/StaticMesh.h"
#include "Rendering/SkeletalMeshRenderData.h"

int32 UMeshTransition::GetCurrentLODIndex(USkeletalMeshComponent* SkeletalMeshComponent)
{
    if(!SkeletalMeshComponent)
        return 0;
    
    int32 ForcedLODIndex = SkeletalMeshComponent->GetForcedLOD();
    if(ForcedLODIndex >= 0)
    {
        return FMath::Max(ForcedLODIndex - 1, 0);
    }
    
    return SkeletalMeshComponent->GetPredictedLODLevel();
}

TArray<int32> UMeshTransition::TriangleIndices(UMeshComponent* MeshComponent, int32 MaterialSlotIndex, int32 LODIndex)
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
    else if (USkeletalMeshComponent* SkeletalMeshComponent = Cast<USkeletalMeshComponent>(MeshComponent))
    {
        if (USkeletalMesh* SkeletalMesh = SkeletalMeshComponent->GetSkeletalMeshAsset())
        {
            if(const FSkeletalMeshRenderData* RenderData = SkeletalMesh->GetResourceForRendering())
            {
                if(RenderData->LODRenderData.Num() > 0)
                {
                   
                    if (LODIndex == -1)
                    {
                        LODIndex = GetCurrentLODIndex(SkeletalMeshComponent);
                        LODIndex = FMath::Clamp(LODIndex, 0, RenderData->LODRenderData.Num() - 1);
                    }
                    
                    const FSkeletalMeshLODRenderData& LOD = RenderData->LODRenderData[LODIndex];
                    for(const FSkelMeshRenderSection& Section : LOD.RenderSections)
                    {
                        if(Section.MaterialIndex == MaterialSlotIndex)
                        {
                            for (uint32 TriangleIndex = 0; TriangleIndex < Section.NumTriangles; ++TriangleIndex)
                            {
                                Triangles.Add(LOD.MultiSizeIndexContainer.GetIndexBuffer()->Get(Section.BaseIndex + TriangleIndex));
                            }
                        }
                    }
                }
            }
        }
    }
    
    return Triangles;
}
