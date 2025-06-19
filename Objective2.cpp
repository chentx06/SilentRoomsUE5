#include "objective2.h"
#include "Animation/WidgetAnimation.h"

//this is just for the objective to move out into view
void Uobjective2::NativeConstruct()
{
    Super::NativeConstruct();
    if (NewAnimation)
    {
        PlayAnimation(NewAnimation, 0.f, 1, EUMGSequencePlayMode::Forward, 1.f, false);
    }
}
