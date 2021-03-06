// Copyright Linus Staf

#include "OpenDoor.h"
#include "Gameframework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	doorOpenerActor = GetWorld()->GetFirstPlayerController()->GetPawn();
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (pressurePlate->IsOverlappingActor(doorOpenerActor)) {
		OpenDoor();
	}
}

void UOpenDoor::OpenDoor() 
{
	AActor *owner = GetOwner();
	FRotator newRotation(0.0f, openAngle, 0.0f);
	owner->SetActorRotation(newRotation);
}
