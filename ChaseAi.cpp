#include "chaseai.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/Character.h"

Achaseai::Achaseai()
{
    PrimaryActorTick.bCanEverTick = true;

    BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
    BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
}

void Achaseai::BeginPlay()
{
    Super::BeginPlay();

    PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &Achaseai::ChasePlayer, 0.2f, false);
}

void Achaseai::ChasePlayer()
{
    if (PlayerPawn)
    {
        if (BlackboardComponent)
        {
            BlackboardComponent->SetValueAsObject("TargetActor", PlayerPawn);
        }

        if (BehaviorTreeComponent)
        {
            BehaviorTreeComponent->StartTree(*BehaviorTree);
        }
    }
}
