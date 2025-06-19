#include "mainmenu1.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"
#include "Components/Slider.h"

void Umainmenu1::NativeConstruct()
{
    Super::NativeConstruct();

    if (PlayButton) PlayButton->OnClicked.AddDynamic(this, &Umainmenu1::OnPlayButtonClicked);
    if (SettingsButton) SettingsButton->OnClicked.AddDynamic(this, &Umainmenu1::OnSettingsButtonClicked);
    if (BackButton) BackButton->OnClicked.AddDynamic(this, &Umainmenu1::OnBackButtonClicked);
    if (ResetButton) ResetButton->OnClicked.AddDynamic(this, &Umainmenu1::OnResetButtonClicked);
    if (MusicSlider) MusicSlider->OnValueChanged.AddDynamic(this, &Umainmenu1::OnMusicSliderChanged);
}

void Umainmenu1::OnPlayButtonClicked()
{
    RemoveFromParent();
    UGameplayStatics::OpenLevel(GetWorld(), "BackroomsLevel0", true);
}

void Umainmenu1::OnSettingsButtonClicked()
{
    if (BorderPanel) BorderPanel->SetVisibility(ESlateVisibility::Visible);
    if (SettingsPanel) SettingsPanel->SetVisibility(ESlateVisibility::Visible);
}

void Umainmenu1::OnBackButtonClicked()
{
    if (BorderPanel) BorderPanel->SetVisibility(ESlateVisibility::Hidden);
    if (SettingsPanel) SettingsPanel->SetVisibility(ESlateVisibility::Hidden);
}

void Umainmenu1::OnResetButtonClicked()
{
    if (MusicSlider) MusicSlider->SetValue(0.5f);
}

void Umainmenu1::OnMusicSliderChanged(float Value)
{
    UGameplayStatics::SetSoundMixClassOverride(
        GetWorld(),
        LoadObject<USoundMix>(nullptr, TEXT("/Game/Sounds/MainMix.MainMix")),
        LoadObject<USoundClass>(nullptr, TEXT("/Game/Levels/MusicClass.MusicClass")),
        Value,
        1.0f,
        0.1f,
        true
    );
}
