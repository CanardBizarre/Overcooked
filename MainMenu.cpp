#include "MainMenu.h"

#include "MainMenuPlayerController.h"
#include "MainMenuHUD.h"

MainMenu::MainMenu() : Level("Main Menu")
{
	canvas = nullptr;
}

void MainMenu::InitFirstScreen(HUD* _hud)
{
	ImageWidget* _firstBackGround = _hud->SpawnWidget<ImageWidget>(RectangleShapeData(GetWindowSize(), "Ui/Menu/Background", JPG));
	canvas->AddChild(_firstBackGround);
	_firstBackGround->SetZOrder(0);
	firstScreen.push_back(_firstBackGround);

	ImageWidget* _logo = _hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(534.0f, 284.0f), "Ui/Menu/Overcooked_logo"));
	canvas->AddChild(_logo);
	_logo->SetOriginAtMiddle();
	_logo->SetPosition(Vector2f(GetWindowSize().x / 2.0f, GetWindowSize().y * 0.3f));
	_logo->SetZOrder(1);
	firstScreen.push_back(_logo);

	LabelWidget* _pressToPlay = _hud->SpawnWidget<LabelWidget>("Press any key to play");
	canvas->AddChild(_pressToPlay);
	_pressToPlay->SetOriginAtMiddle();
	_pressToPlay->SetFont("segoe-ui-black", TTF);
	_pressToPlay->SetFillColor(Color(77, 88, 105));
	_pressToPlay->SetPosition(Vector2f(GetWindowSize().x / 2.0f, GetWindowSize().y * 0.6f));
	_pressToPlay->SetZOrder(1);
	firstScreen.push_back(_pressToPlay);
}

void MainMenu::InitLevel()
{
	Super::InitLevel();

	HUD* _hud = GetGameMode()->GetHUD();

	// Init Canvas
	canvas = _hud->SpawnWidget<CanvasWidget>();
	canvas->SetDebugMode(true);
	canvas->SetSize(CAST(Vector2f,(GetWindowSize())));

	InitFirstScreen(_hud);

	//for (Widget* _current : firstScreen)
	//{
	//	_current->SetVisibility(Hidden);
	//}


	GetGameMode()->GetHUD()->AddToViewport(canvas);
}
