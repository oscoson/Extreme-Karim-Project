// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
// Author: Evan Kilburn

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "LightRay.generated.h"

UCLASS()
class EXTREMEKARIM_API ALightRay : public APawn
{
	GENERATED_BODY()
	
protected:

	// Root component to hold the rest of elements together
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MoveActor")
	class USceneComponent* RootScene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MoveActor")
	class UStaticMeshComponent* Mesh;


protected:
	UPROPERTY(EditAnywhere, Category = "MoveActor")
	float Speed;

public:	
	ALightRay();


public:	
	virtual void Tick(float DeltaTime) override;
};