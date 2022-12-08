// Author: Evan Kilburn


#include "LightRay.h"
#include "ExtremeKarim.h"
#include "Components/StaticMeshComponent.h"



ALightRay::ALightRay()
{
	// Create root
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootScene;

	// Create Static Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));	
	Mesh->SetupAttachment(RootComponent);

	PrimaryActorTick.bCanEverTick = true;

}

void ALightRay::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// -2240 to 1770 on X
	// -180 to 2000 on Y
	FVector Location = GetActorLocation();
	if (Location.Z < -10){
		Location.X = FMath::RandRange(-1300, 1770);
		Location.Z = 2600;
	}
	Location.Z -= 10;
	SetActorLocation(Location);
}

