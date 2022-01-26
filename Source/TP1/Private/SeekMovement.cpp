// Fill out your copyright notice in the Description page of Project Settings.


#include "SeekMovement.h"

#include "AIPawn.h"

SeekMovement::SeekMovement(APawn* AiPawn, FVector TargetPos, float MaxSpeed, FVector Vel)
{
	AiPos = AiPawn->GetActorLocation();
	Velocity= Vel;
	this->TargetPos = TargetPos;
	this->MaxSpeed = MaxSpeed;
}

SeekMovement::~SeekMovement()
{

}

FVector SeekMovement::Seek()
{
	FVector DesiredVelocity = (TargetPos - AiPos).GetUnsafeNormal() * MaxSpeed;
	return DesiredVelocity - Velocity;
}
//normalize(v) = to_unit(v) = v/|v|