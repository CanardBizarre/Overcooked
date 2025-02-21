#include "ChooseMapLevel.h"
#include "LevelManager.h"
#include "Level_1_1.h"
#include "Level_2_1.h"
#include "Level_3_1.h"
#include "Level_4_1.h"
#include "Level_5_1.h"
#include "TargetCamera.h"

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

	MeshActor* _background = SpawnActor<MeshActor>(RectangleShapeData(Vector2f(1900, 1080), "Hub/Background_Hub", PNG));
	_background->SetPosition({ 0.0f, 0.0f });

	TriggerBox* _triggerLevel_1 = SpawnActor<TriggerBox>([&]() {M_LEVEL.SetLevel(new Level_1_1()); }, RectangleShapeData({ 124.0f,124.0f }, "Hub/Level_1"));
	_triggerLevel_1->SetPosition({290.0f,525.0f});
	//triggerLevel_1->Rotate(degrees(90));
	TriggerBox* _triggerLevel_2 = SpawnActor<TriggerBox>([&](){M_LEVEL.SetLevel(new Level_2_1()); }, RectangleShapeData({ 124.0f,124.0f }, "Hub/Level_2"));
	_triggerLevel_2->SetPosition({ 517.0f,377.0f });
	//_triggerLevel_2->Rotate(degrees(90));
	TriggerBox* _triggerLevel_3 = SpawnActor<TriggerBox>([&](){M_LEVEL.SetLevel(new Level_3_1()); }, RectangleShapeData({ 124.0f,124.0f }, "Hub/Level_3"));
	_triggerLevel_3->SetPosition({942.0f,551.0f});
	//_triggerLevel_3->Rotate(degrees(90));
	TriggerBox* _triggerLevel_4 = SpawnActor<TriggerBox>([&](){M_LEVEL.SetLevel(new Level_4_1()); }, RectangleShapeData({ 124.0f,124.0f }, "Hub/Level_4"));
	_triggerLevel_4->SetPosition({1215.0f,440.0f});
	//_triggerLevel_4->Rotate(degrees(90));
	TriggerBox* _triggerLevel_5 = SpawnActor<TriggerBox>([&](){M_LEVEL.SetLevel(new Level_5_1()); }, RectangleShapeData({ 124.0f,124.0f }, "Hub/Level_5"));
	_triggerLevel_5->SetPosition({1555.0f,719.0f});
	//_triggerLevel_5->Rotate(degrees(90));

	player = SpawnActor<ChooseMapPawn>();
	player->SetPosition({ 290.0f,525.0f });
}
