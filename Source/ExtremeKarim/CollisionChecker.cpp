// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionChecker.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"

// Sets default values
ACollisionChecker::ACollisionChecker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(32.f, 32.f, 32.f));
	CollisionBox->SetCollisionProfileName("Trigger");
	RootComponent = CollisionBox;

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ACollisionChecker::OnOverlapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &ACollisionChecker::OnOverlapEnd);
}

// Called when the game starts or when spawned
void ACollisionChecker::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollisionChecker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACollisionChecker::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OtherActor->SetActorLocation(startLocation);

}

void ACollisionChecker::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//pass, used to check when collision ends
}

