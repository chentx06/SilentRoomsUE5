#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "mainmenu1.generated.h"

class UButton;
class USlider;
class UBorder;
class UVerticalBox;

UCLASS()
class YOURGAME_API Umainmenu1 : public UUserWidget
{
    GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;

    UPROPERTY(meta = (BindWidget))
    UButton* PlayButton;

    UPROPERTY(meta = (BindWidget))
    UButton* SettingsButton;

    UPROPERTY(meta = (BindWidget))
    UButton* BackButton;

    UPROPERTY(meta = (BindWidget))
    UButton* ResetButton;

    UPROPERTY(meta = (BindWidget))
    USlider* MusicSlider;

    UPROPERTY(meta = (BindWidget))
    UBorder* BorderPanel;

    UPROPERTY(meta = (BindWidget))
    UVerticalBox* SettingsPanel;

private:
    UFUNCTION()
    void OnPlayButtonClicked();

    UFUNCTION()
    void OnSettingsButtonClicked();

    UFUNCTION()
    void OnBackButtonClicked();

    UFUNCTION()
    void OnResetButtonClicked();

    UFUNCTION()
    void OnMusicSliderChanged(float Value);
};
