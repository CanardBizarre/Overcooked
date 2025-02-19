#include "DebugLevel.h"
#include "CanvasWidget.h"
#include "ImageWidget.h"
#include "MeshActor.h"
#include "LabelWidget.h"
#include "TimerManager.h"

#include "WorkPlan.h"

#include "TestDummy.h"
#include "LevelLoader.h"
#include "FileManager.h"

using namespace File;

DebugLevel::DebugLevel() : GameplayLevel("Debug")
{
	hud = GetGameMode()->GetHUD();
	hud->SpawnWidget<LabelWidget>("null");
	hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(300.0f, 150.0f), "UI/timer_slide"));
	hud->SpawnWidget<CanvasWidget>("Canvas");

	chronoWidget->GetLabel()->SetText(chronoWidget->GetChrono()->GetTime());
	player = nullptr;
}

DebugLevel::~DebugLevel()
{
	delete chronoWidget;
	delete hud;
}

void DebugLevel::InitLevel()
{
	Super::InitLevel();
	SpawnActor<MeshActor>(RectangleShapeData(GetWindowSize(), "BackGround_2", JPG), "BackGround");

	player = SpawnActor<PlayerPawn>();
	player->SetPosition(Vector2f(window.getSize()) / 2.0f);
	const string& _folders = "LevelsData/";
	const string& _path = _folders + "DebugLevel";

	const vector<string>& _texts = M_FILE.ReadFile(_path.c_str());

	M_LEVELLOADER.InterpretString(_texts);
}
