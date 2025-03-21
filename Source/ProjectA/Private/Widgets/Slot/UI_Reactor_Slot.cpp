// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Slot/UI_Reactor_Slot.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/UniformGridPanel.h"
#include "Components/ScaleBox.h"
#include "GameInstance/BaseGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Styling/SlateBrush.h"


//#include "Widgets/PopUp/UI_Parts_Popup.h"
#include "Widgets/PopUp/UI_Reactor_Popup.h"

void UUI_Reactor_Slot::UpdateInfo(FItemInfo_ Data_)
{
	ItemData_Num = Data_;

	Item_Level->SetText(FText::AsNumber(Data_.Item_Number));

	Item_Image->SetBrushFromTexture(Data_.AssetData.ItemImage);

	Item_TierBar->SetBrushFromTexture(Data_.AssetData.TierBar);

	Item_TierGlow->SetBrushTintColor(FSlateColor(FLinearColor(Data_.AssetData.Rank_Color.R, Data_.AssetData.Rank_Color.G, Data_.AssetData.Rank_Color.B)));

	UUI_Reactor_Popup* MainslotPopup= Cast<UUI_Reactor_Popup>(GetWidgetFromName(TEXT("Reactor_PopUp")));

	if (MainslotPopup)
	{
		MainslotPopup->UpdatePopUpInfo(Data_);
	}
}

FReply UUI_Reactor_Slot::NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::RightMouseButton)
	{

		UScaleBox* ParentScaleBox = Cast<UScaleBox>(GetParent());
		UUniformGridPanel* ParentGridPanel = Cast<UUniformGridPanel>(ParentScaleBox->GetParent());

		if (ParentGridPanel)
		{

			int32 Index = ParentGridPanel->GetChildIndex(ParentScaleBox);

			UBaseGameInstance* GameInstance = Cast<UBaseGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
			GameInstance->ChangeWeaponDelegate(Index, ItemData_Num);

		}
		else
			UE_LOG(LogTemp, Warning, TEXT("ssssssssssss"));

	}
	return FReply::Handled();
}
