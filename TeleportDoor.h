#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "teleportdoor.generated.h"

class UBoxComponent;
class ABP_FirstPersonCharacter;

UCLASS()
class YOURGAME_API Ateleportdoor : public AActor
{
    GENERATED_BODY()
    
public:
    Ateleportdoor();
protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Components")
    UBoxComponent* TeleportTrigger;

    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UPROPERTY(EditAnywhere, Category= "Teleport")
    FName DestinationLevel= "BackroomsLevel1";
};
