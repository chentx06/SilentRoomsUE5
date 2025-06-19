#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "chaseai.generated.h"

UCLASS()
class YOURGAME_API Achaseai : public AAIController
{
    GENERATED_BODY()

public:
    Achaseai();

protected:
    virtual void BeginPlay() override;

private:
    FTimerHandle TimerHandle;
    APawn* PlayerPawn;

    void ChasePlayer();
};
