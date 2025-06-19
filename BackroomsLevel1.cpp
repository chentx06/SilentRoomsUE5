
#include "BackroomsLevel1.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

ABackroomsLevel1::ABackroomsLevel1()
{
    PrimaryActorTick.bCanEverTick = false;
}

void ABackroomsLevel1::BeginPlay()
{
    Super::BeginPlay();

    if (ObjectiveWidgetClass)
    {
        UUserWidget* ObjectiveWidget = CreateWidget<UUserWidget>(
            GetWorld(),
            ObjectiveWidgetClass,
            TEXT("ObjectiveWidget")
        );
        
        if (ObjectiveWidget)
        {
            ObjectiveWidget->AddToViewport();
        }
    }
}
