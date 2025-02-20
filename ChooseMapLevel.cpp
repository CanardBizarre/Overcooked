#include "ChooseMapLevel.h"
#include "LevelManager.h"
#include "Level_1_1.h"
#include "Level_2_1.h"
#include "Level_3_1.h"
#include "Level_4_1.h"
#include "Level_5_1.h"

ChooseMapLevel::ChooseMapLevel() : Level("ChooseMapLevel")
{
	player = nullptr;
}

ChooseMapLevel::~ChooseMapLevel()
{
}

void ChooseMapLevel::InitLevel()
{
	Super::InitLevel();

	SpawnActor<ChooseMapPawn>();
	TriggerBox* _triggerLevel_1 = SpawnActor<TriggerBox>([&](){M_LEVEL.SetLevel(new Level_1_1()); }, RectangleShapeData({ 30.0f,30.0f }));
	_triggerLevel_1->SetPosition({200.0f,200.0f});
	TriggerBox* _triggerLevel_2 = SpawnActor<TriggerBox>([&](){M_LEVEL.SetLevel(new Level_2_1()); }, RectangleShapeData({ 30.0f,30.0f }));
	_triggerLevel_2->SetPosition({400.0f,350.0f});
	TriggerBox* _triggerLevel_3 = SpawnActor<TriggerBox>([&](){M_LEVEL.SetLevel(new Level_3_1()); }, RectangleShapeData({ 30.0f,30.0f }));
	_triggerLevel_3->SetPosition({450.0f,450.0f});

}
