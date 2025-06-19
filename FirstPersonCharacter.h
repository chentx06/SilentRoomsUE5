#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "FirstPersonCharacter.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class YOURPROJECT_API AFirstPersonCharacter : public ACharacter
{
    GENERATED_BODY()


public:
    AFirstPersonCharacter();
protected:
    virtual void BeginPlay() override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Input)
    UInputMappingContext * DefaultMappingContext;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Input)
    UInputAction * JumpAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Input)
    UInputAction * MoveAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Input)
    UInputAction * LookAction;

    //call back 
    void OnJumpStarted();
    void OnJumpCompleted();
    void Move(const FInputActionValue& Value);
    void Look(const FInputActionValue& Value);

    // change handling
    virtual void OnControllerChanged(APlayerController* OldController, APlayerController* NewController);
};
