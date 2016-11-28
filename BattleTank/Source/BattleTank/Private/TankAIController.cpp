// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Public/TankAIController.h"


ATank* ATankAIController::GetPossessedTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PossessedTank = GetPossessedTank();
	if (!PossessedTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing a tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *(PossessedTank->GetName()));
	}
}