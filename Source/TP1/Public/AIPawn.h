// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AIPawn.generated.h"

UCLASS()
class TP1_API AAIPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAIPawn();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// class Vehicule
	UPROPERTY(Editinstanceonly, BlueprintReadOnly, Category = Limiter, meta = (AllowPrivateAccess = "true"))
	float Mass = 10.f;

	UPROPERTY(editinstanceonly, BlueprintReadOnly, Category = Limiter, meta = (AllowPrivateAccess = "true"))
	float MaxSpeed = 800.f;

	UPROPERTY(editinstanceonly, BlueprintReadOnly, Category = Limiter, meta = (AllowPrivateAccess = "true"))
	float MaxForce = 12.f;

	UPROPERTY(editinstanceonly, BlueprintReadOnly, Category = Limiter, meta = (AllowPrivateAccess = "true" , ClampMin = "0", ClampMax = "3", UIMin = "0", UIMax = "3"))
	int MovementType = 0;

	UPROPERTY(EditInstanceOnly, Category = "Target")
	APawn* Target;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FVector Truncate(FVector Vect, float maxS);
private:

	UPROPERTY(VisibleAnywhere, Category = ArcanoidePawn, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* RootScene;

	UPROPERTY(VisibleAnywhere, Category = ArcanoidePawn, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* CollisionBox;

	UPROPERTY(VisibleAnywhere, Category = ArcanoidePawn, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* MeshComp;

	FVector Velocity;


};
