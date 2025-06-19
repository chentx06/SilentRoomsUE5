#include "MainMenu.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "UMG.h"
#include "UMGBlueprintFunctionLibrary.h"

AMainMenu::AMainMenu()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AMainMenu::BeginPlay()
{
    Super::BeginPlay();

    if (MainSoundMix)
    {
        UGameplayStatics::PushSoundMixModifier(this, MainSoundMix);
    }

    if (MainMenuWidgetClass)
    {
        UUserWidget* MainMenuWidget = CreateWidget<UUserWidget>(GetWorld(), MainMenuWidgetClass);
        if (MainMenuWidget)
        {
            MainMenuWidget->AddToViewport();
            
            APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
            if (PlayerController)
            {
                UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerController, MainMenuWidget, EMouseLockMode::DoNotLock, false);
                PlayerController->bShowMouseCursor = true;
            }
        }
    }
}
