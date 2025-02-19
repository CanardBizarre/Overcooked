#include "DebugLevel.h"
#include "CanvasWidget.h"
#include "ImageWidget.h"
#include "MeshActor.h"
#include "LabelWidget.h"
#include "TimerManager.h"
#include "Score.h"

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

	HUD* _hud = GetGameMode()->GetHUD();
	CanvasWidget* _canvas = _hud->SpawnWidget<CanvasWidget>("Canvas");


	ImageWidget* _image = _hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(300.0f, 150.0f), "UI/timer_slide"));
	_image->SetOriginAtMiddle();
	_image->SetPosition(Vector2f(400.0f, 400.0f));
	_canvas->AddChild(_image);

	label = _hud->SpawnWidget<LabelWidget>(chrono->GetTime());
	label->SetFillColor(Color::White);
	label->SetFont("Overcooked", TTF);
	label->SetOriginAtMiddle();
	label->SetPosition(Vector2f(400.0f, 400.0f));
	label->SetZOrder(1);


	Score* _score = new Score(GetGameMode()->GetHUD());
	_score->InitScore(GetWindowSize());

	//new Timer([&]() {_score.AddScore(5); }, seconds(1), true, true);
	
	/*new Timer([&]() {chrono->DecrementCurrentTime(); LOG(Warning, to_string(chrono->GetCurrentTime()));
					 label->SetText(chrono->GetTime()); }, seconds(1), true, true);
	_canvas->AddChild(label);
	_canvas->SetPosition(Vector2f(400.0f, 400.0f));
	_hud->AddToViewport(_canvas);
	_canvas = _hud->SpawnWidget<CanvasWidget>();*/
	player = SpawnActor<PlayerPawn>();
	player->SetPosition(Vector2f(window.getSize()) / 2.0f);
	const string& _folders = "LevelsData/";
	const string& _path = _folders + "DebugLevel";

	const vector<string>& _texts = M_FILE.ReadFile(_path.c_str());

	M_LEVELLOADER.InterpretString(_texts);
}
