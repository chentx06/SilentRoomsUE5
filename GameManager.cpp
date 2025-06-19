#include "GameManager.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetTextLibrary.h"

AGameManager::AGameManager()
{
    PrimaryActorTick.bCanEverTick = false;
    ObjectsCollected = 0;
}

void AGameManager::BeginPlay()
{
    Super::BeginPlay();

    if (ObjectiveWidgetClass)
    {
        ObjectiveUI = CreateWidget<UUserWidget>(GetWorld(), ObjectiveWidgetClass);
        if (ObjectiveUI)
        {
            ObjectiveUI->AddToViewport();
        }
    }
}

void AGameManager::OnObjectCollected()
{
    ObjectsCollected++;
    
    FText CountText = UKismetTextLibrary::Conv_IntToText(ObjectsCollected);
    FText FormattedText = FText::Format(NSLOCTEXT("GameManager", "ObjectiveFormat", "Collect objects ({0}/6)"), CountText);
    
    UpdateObjectiveText(FormattedText);
}

void AGameManager::UpdateObjectiveText(const FText& NewText)
{
    if (ObjectiveUI)
    {
        // This assumes your widget has a function called UpdateObjectiveText that takes an FText parameter
        // You'll need to implement this function in your WBP_Objective widget
        UFunction* UpdateFunc = ObjectiveUI->FindFunction(FName("UpdateObjectiveText"));
        if (UpdateFunc)
        {
            struct FObjectiveTextParams
            {
                FText NewText;
            };
            
            FObjectiveTextParams Params;
            Params.NewText = NewText;
            
            ObjectiveUI->ProcessEvent(UpdateFunc, &Params);
        }
    }
}
