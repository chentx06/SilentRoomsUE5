#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MainMenu.generated.h"

class UUserWidget;
class USoundMix;

UCLASS()
class YOURGAME_API AMainMenu : public AActor
{
    GENERATED_BODY()
    
public:
    AMainMenu();

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(EditAnywhere)
    TSubclassOf<UUserWidget> MainMenuWidgetClass;
    
    UPROPERTY(EditAnywhere)
    USoundMix* MainSoundMix;
};
