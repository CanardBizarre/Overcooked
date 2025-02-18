#include "DebugLevel.h"
#include "CanvasWidget.h"
#include "ImageWidget.h"
#include "CustomWidget.h"
#include "MeshActor.h"
#include "LabelWidget.h"
#include "TimerManager.h"

DebugLevel::DebugLevel() : Level("Debug")
{
	chrono = new Chronometer(1, 30);
}

DebugLevel::~DebugLevel()
{
	delete chrono;
}

void DebugLevel::InitLevel()
{
	Super::InitLevel();

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
	
	
	new Timer([&]() {chrono->DecrementCurrentTime(); LOG(Warning, to_string(chrono->GetCurrentTime()));
					 label->SetText(chrono->GetTime()); }, seconds(1), true, true);
	_canvas->AddChild(label);
	_canvas->SetPosition(Vector2f(400.0f, 400.0f));
	_hud->AddToViewport(_canvas);
	_canvas = _hud->SpawnWidget<CanvasWidget>();
}
