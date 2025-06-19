#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BackroomsLevel1.generated.h"

class UUserWidget;

UCLASS()
class YOURGAME_API ABackroomsLevel1 : public AActor
{
    GENERATED_BODY()
    
public:
    ABackroomsLevel1();

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(EditAnywhere)
    TSubclassOf<UUserWidget> ObjectiveWidgetClass;
};
