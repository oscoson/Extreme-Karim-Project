// Author: Akshaj Darbar


#include "PortalActor.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "MainMenuWidget.cpp"

// Sets default values
APortalActor::APortalActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("PortalComponent"));
	CollisionBox->SetBoxExtent(FVector(128.f, 128.f, 128.f));
	CollisionBox->SetCollisionProfileName("Trigger");
	RootComponent = CollisionBox;

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &APortalActor::OnOverlapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &APortalActor::OnOverlapEnd);


	
	static ConstructorHelpers::FClassFinder<UUserWidget> MainMenuWidget(TEXT("/Game/2DSideScroller/Maps/MainMenu"));

	if (!ensure(MainMenuWidget.Class != nullptr)) return;

	MainMenuWidgetClass = MainMenuWidget.Class;
	UE_LOG(LogTemp, Warning, TEXT("We found class %s"), *MainMenuWidgetClass->GetName());

}

// Called when the game starts or when spawned
void APortalActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APortalActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APortalActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, "Portal Entered. Game Success!");
	/*UUserWidget* MainMenu = CreateWidget<UUserWidget>(this, MainMenuWidgetClass);
	MainMenu->AddToViewport();

	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(MainMenu->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	*/
	UUserWidget* MenuWidget = CreateWidget<UUserWidget>(GetGameInstance(), MainMenuWidgetClass);
	if (MenuWidget) {
		MenuWidget->AddToViewport();

		APlayerController* PC = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld()));
		FInputModeUIOnly InputModeData;
		InputModeData.SetWidgetToFocus(MenuWidget->TakeWidget());
		InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

		PC->SetInputMode(InputModeData);
		PC->bShowMouseCursor = true;
	}
}

void APortalActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "Portal Overlap End");
}