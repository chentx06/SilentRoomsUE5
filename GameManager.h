#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"
#include "GameManager.generated.h"

UCLASS()
class YOURPROJECT_API AGameManager : public AActor
{
    GENERATED_BODY()
    
public:    
    AGameManager();

protected:
    virtual void BeginPlay() override;

public:
    UFUNCTION()
    void OnObjectCollected();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game Manager")
    int32 ObjectsCollected;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game Manager")
    TSubclassOf<class UUserWidget> ObjectiveWidgetClass;

    UPROPERTY()
    class UUserWidget* ObjectiveUI;

private:
    void UpdateObjectiveText(const FText& NewText);
};
