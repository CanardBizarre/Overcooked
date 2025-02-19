#include "DebugLevel.h"
#include "CanvasWidget.h"
#include "ImageWidget.h"
#include "CustomWidget.h"
#include "MeshActor.h"
#include "LabelWidget.h"
#include "TimerManager.h"

DebugLevel::DebugLevel() : Level("Debug")
{
	hud = GetGameMode()->GetHUD();
	chronoWidget = new CustomChrono(hud->SpawnWidget<LabelWidget>("null"),
									hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(300.0f, 150.0f), "UI/timer_slide")),
									hud->SpawnWidget<CanvasWidget>("Canvas"));
	chronoWidget->GetLabel()->SetText(chronoWidget->GetChrono()->GetTime());
	hud->AddToViewport(chronoWidget->GetCanvas());
}

DebugLevel::~DebugLevel()
{
	delete chronoWidget;
	delete hud;
}

void DebugLevel::InitLevel()
{
	Super::InitLevel();
	
}
