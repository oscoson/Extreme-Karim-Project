// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class EXTREMEKARIM_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	//virtual void NativeConstruct() override;

public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UImage* BackgroundImage;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UImage* PlayButtonImage;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UImage* LevelButtonImage;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UImage* SettingsButtonImage;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UImage* QuitButtonImage;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* PlayButton;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* LevelButton;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* SettingsButton;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* QuitButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UVerticalBox* MainMenuVerticalBox;
	
};
