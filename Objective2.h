#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "objective2.generated.h"

class UWidgetAnimation;

UCLASS()
class YOURGAME_API Uobjective2 : public UUserWidget
{
    GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;

    UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim))
    UWidgetAnimation* NewAnimation;
};
