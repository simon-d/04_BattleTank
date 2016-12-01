// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	ATank* GetControlledTank() const;

	void AimTowardsCrosshair();

	UPROPERTY(EditDefaultsOnly, Category = "Controls")
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly, Category = "Controls")
	float CrosshairYLocation = 0.333;

	UPROPERTY(EditDefaultsOnly, Category = "Controls")
	float LineTraceRange = 1000000;

	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
