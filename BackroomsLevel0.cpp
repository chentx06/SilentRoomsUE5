#include "BackroomsLevel0.h"
#include "Kismet/GameplayStatics.h"
#include "UMGBlueprintFunctionLibrary.h"

ABackroomsLevel0::ABackroomsLevel0()
{
    PrimaryActorTick.bCanEverTick = false;
    ObjectsCollected = 0;
}

void ABackroomsLevel0::BeginPlay()
{
    Super::BeginPlay();

    APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
    if (PlayerController)
    {
        UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController, false);
    }
}
