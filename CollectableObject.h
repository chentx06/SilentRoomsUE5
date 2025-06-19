#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollectableObject.generated.h"

UCLASS()
class YOURPROJECT_API ACollectableObject : public AActor
{
    GENERATED_BODY()
    
public:    
    ACollectableObject();
protected:
    virtual void BeginPlay() override;



    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    class UPrimitiveComponent* InteractionBox;


    UPROPERTY(BlueprintReadWrite)
    bool CanPickUp;
    UFUNCTION()
    void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    UFUNCTION()
    void OnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent,  AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    void OnEKeyPressed();
};
