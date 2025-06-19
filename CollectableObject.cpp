#include "CollectableObject.h"
#include "Components/PrimitiveComponent.h"
#include "FirstPersonCharacter.h"
#include "GameManager.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

ACollectableObject::ACollectableObject()
{
    PrimaryActorTick.bCanEverTick= false;
}

void ACollectableObject ::BeginPlay()
{
    Super::BeginPlay();

    if (InteractionBox)
    {
        InteractionBox ->OnComponentBeginOverlap.AddDynamic(this, &ACollectableObject::OnComponentBeginOverlap);
        InteractionBox ->OnComponentEndOverlap.AddDynamic(this, &ACollectableObject::OnComponentEndOverlap);
    }

    EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));
}

void ACollectableObject::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (Cast<AFirstPersonCharacter>(OtherActor))
    {
        CanPickUp= true;
    }
}
void ACollectableObject::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (Cast<AFirstPersonCharacter>(OtherActor))
    {
        CanPickUp= false;
    }
}
void ACollectableObject::OnEKeyPressed()
{
    if (CanPickUp)
    {
        TArray<AActor *> FoundActors;
        UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGameManager::StaticClass(), FoundActors);
        if (FoundActors.Num() > 0)
        {
            if (AGameManager* GameManager= Cast<AGameManager>(FoundActors[0]))
            {
                GameManager->OnObjectCollected();
            }
        }
        Destroy();
    }
}
