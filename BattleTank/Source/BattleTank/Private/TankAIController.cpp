// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Public/Tank.h"
#include "Public/TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (PlayerTank && ControlledTank)
	{
		// Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius);

		// Aim at player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// Fire if ready
		ControlledTank->Fire();
	}
}
