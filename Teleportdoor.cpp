#include "teleportdoor.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "BP_FirstPersonCharacter.h"

Ateleportdoor::Ateleportdoor()
{
    PrimaryActorTick.bCanEverTick = false;
    TeleportTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("TeleportTrigger"));
    RootComponent = TeleportTrigger;
}

void Ateleportdoor::BeginPlay()
{
    Super::BeginPlay();
    if (TeleportTrigger)
    {
        TeleportTrigger->OnComponentBeginOverlap.AddDynamic(this, &Ateleportdoor::OnOverlapBegin);
    }
}

//collision
void Ateleportdoor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (ABP_FirstPersonCharacter* Player = Cast<ABP_FirstPersonCharacter>(OtherActor))
    {
        UGameplayStatics::OpenLevel(GetWorld(), DestinationLevel, true);
    }
}
