#include "MainMenu.h"

#include "MainMenuPlayerController.h"
#include "MainMenuPawn.h"
#include "MainMenuHUD.h"

MainMenu::MainMenu() : Level("Main Menu")
{
	canvas = nullptr;
}

MainMenu::~MainMenu()
{
}

void MainMenu::ChangeScreen(const int _increment)
{
	if (_increment > 0)
	{
		for (int _index = 0; _index < _increment; _index++)currentScreen++;

	}

	for (vector<Widget*> _currentScreen : allScreen)
	{
		VisibilityType _visibility = Hidden; 
		if (_currentScreen == (*currentScreen)) _visibility = VisibilityType::Visible;
		for (Widget* _currentWidget : _currentScreen)
		{
			_currentWidget->SetVisibility(_visibility);
		}
	}
}

void MainMenu::SetupFirstScreen()
{
	allScreen.push_back(firstScreen);
	allScreen.push_back(secondScreen);

	currentScreen = allScreen.begin();
	ChangeScreen(0);
}


void MainMenu::InitFirstScreen(HUD* _hud)
{
	ImageWidget* _firstBackGround = _hud->SpawnWidget<ImageWidget>(RectangleShapeData(GetWindowSize(), "Ui/Menu/Background", JPG));
	canvas->AddChild(_firstBackGround);
	_firstBackGround->SetZOrder(0);

	ImageWidget* _logo = _hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(534.0f, 284.0f), "Ui/Menu/Overcooked_logo"));
	canvas->AddChild(_logo);
	_logo->SetOriginAtMiddle();
	_logo->SetPosition(Vector2f(GetWindowSize().x / 2.0f, GetWindowSize().y * 0.3f));
	_logo->SetZOrder(1);

	// TODO Implementation manette
	LabelWidget* _pressToPlay = _hud->SpawnWidget<LabelWidget>("Press enter to play");
	canvas->AddChild(_pressToPlay);
	_pressToPlay->SetOriginAtMiddle();
	_pressToPlay->SetFont("segoe-ui-black", TTF);
	_pressToPlay->SetFillColor(Color(77, 88, 105));
	_pressToPlay->SetPosition(Vector2f(GetWindowSize().x / 2.0f, GetWindowSize().y * 0.6f));
	_pressToPlay->SetZOrder(1);


	firstScreen.push_back(_firstBackGround);
	firstScreen.push_back(_logo);
	firstScreen.push_back(_pressToPlay);
}

void MainMenu::InitSecondScreen(HUD* _hud)
{
	ImageWidget* _secondBackGround = _hud->SpawnWidget<ImageWidget>(RectangleShapeData(GetWindowSize(), "Ui/Menu/Table", JPG));
	canvas->AddChild(_secondBackGround);
	_secondBackGround->SetZOrder(0);

	ImageWidget* _book = _hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(800.0f, 541.4f), "Ui/Menu/Book"));
	canvas->AddChild(_book);
	_book->SetOriginAtMiddle();
	_book->SetPosition(Vector2f(GetWindowSize().x / 2.0f - 100.0f, GetWindowSize().y /2.0f));
	_book->Rotate(degrees(30.0f));
	_book->SetZOrder(1);

	LabelWidget* _campaign = _hud->SpawnWidget<LabelWidget>("CAMPAIGN");
	canvas->AddChild(_campaign);
	_campaign->SetFont("segoe-ui-black", TTF);
	_campaign->SetFillColor(Color(77, 88, 105));
	_campaign->SetPosition(Vector2f(GetWindowSize().x * 0.5f, GetWindowSize().y * 0.2f));
	_campaign->SetZOrder(2);

	LabelWidget* _option = _hud->SpawnWidget<LabelWidget>("OPTION");
	canvas->AddChild(_option);
	_option->SetFont("segoe-ui-black", TTF);
	_option->SetFillColor(Color(77, 88, 105));
	_option->SetPosition(Vector2f(GetWindowSize().x * 0.5f, GetWindowSize().y * 0.4f));
	_option->SetZOrder(2);

	LabelWidget* _credits = _hud->SpawnWidget<LabelWidget>("CREDITS");
	canvas->AddChild(_credits);
	_credits->SetFont("segoe-ui-black", TTF);
	_credits->SetFillColor(Color(77, 88, 105));
	_credits->SetPosition(Vector2f(GetWindowSize().x * 0.5f, GetWindowSize().y * 0.6f));
	_credits->SetZOrder(2);


	ImageWidget* _option1 = _hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(22.5f,22.5f), "Ui/Menu/Arrow"));
	canvas->AddChild(_option1);
	_option1->SetOriginAtMiddle();
	_option1->SetPosition(Vector2f(GetWindowSize().x * 0.45f, GetWindowSize().y * 0.23f));
	_option1->SetZOrder(2);


	ImageWidget* _option2 = _hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(22.5f, 22.5f), "Ui/Menu/Arrow"));
	canvas->AddChild(_option2);
	_option2->SetOriginAtMiddle();
	_option2->SetPosition(Vector2f(GetWindowSize().x * 0.45f, GetWindowSize().y * 0.43f));
	_option2->SetZOrder(2);

	ImageWidget* _option3 = _hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(22.5f, 22.5f), "Ui/Menu/Arrow"));
	canvas->AddChild(_option3);
	_option3->SetOriginAtMiddle();
	_option3->SetPosition(Vector2f(GetWindowSize().x * 0.45f, GetWindowSize().y * 0.63f));
	_option3->SetZOrder(2);

	// Second Screen vector
	secondScreen.push_back(_book);
	secondScreen.push_back(_secondBackGround);
	secondScreen.push_back(_campaign);
	secondScreen.push_back(_option);
	secondScreen.push_back(_credits);
	secondScreen.push_back(_option1);
	secondScreen.push_back(_option2);
	secondScreen.push_back(_option3);

	// option Vector
	options.push_back(_option1);
	options.push_back(_option2);
	options.push_back(_option3);

	currentOption = options.begin();

}

void MainMenu::ChooseScreen(const ScreenType& _screen)
{
	currentScreen = allScreen.begin();
	ChangeScreen(_screen);
}


void MainMenu::InitLevel()
{
	Super::InitLevel();
	SpawnActor<MainMenuPawn>();

	HUD* _hud = GetGameMode()->GetHUD();

	canvas = _hud->SpawnWidget<CanvasWidget>();
	canvas->SetDebugMode(true);
	canvas->SetSize(CAST(Vector2f, GetWindowSize()));

	// Init all screen
	InitFirstScreen(_hud);
	InitSecondScreen(_hud);



	SetupFirstScreen();

	GetGameMode()->GetHUD()->AddToViewport(canvas);
}