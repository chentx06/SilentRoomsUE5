#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BackroomsLevel0.generated.h"

UCLASS()
class YOURGAME_API ABackroomsLevel0 : public AActor
{
    GENERATED_BODY()
    
public:
    ABackroomsLevel0();

    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    int32 ObjectsCollected;

protected:
    virtual void BeginPlay() override;
};
