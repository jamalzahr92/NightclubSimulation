#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AudioAnalyzerCPP.generated.h"

UCLASS()
class VISUALCOMPUTINGV2C_API AAudioAnalyzerCPP : public AActor
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(BlueprintReadOnly, Category = "Audio")
    float BassValue = 0.0f;
};