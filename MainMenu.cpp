#include "MainMenu.h"

#include "MainMenuPlayerController.h"
#include "MainMenuPawn.h"
#include "MainMenuHUD.h"

#include "DebugLevel.h"
#include "Level_1_1.h"
#include "ChooseMapLevel.h"

#include "LevelManager.h"


MainMenu::MainMenu() : Level("Main Menu")
{
	canvas = nullptr;
}

MainMenu::~MainMenu()
{
}


void MainMenu::ChangeOption(const int _increment)
{
	if (_increment > 0)
	{
		for (int _index = 0; _index < _increment; _index++)
		{
			if (IsLastChoice())
			{
				currentChoice = choices.begin();
				continue;
			}
			currentChoice++;
		}

	}
	else if (_increment < 0)
	{
		for (int _index = 0; _index > _increment; _index--)
		{
			if (IsFirstChoice())
			{
				currentChoice = --choices.end();
				continue;

			}
			currentChoice--;
		}
	}

	for (Widget* _option : choices)
	{
		VisibilityType _visibility = Hidden;
		if (_option == (*currentChoice))
		{
			_visibility = Visible;
		}
		_option->SetVisibility(_visibility);
	}
}

void MainMenu::SetupOption()
{
	currentChoice = choices.begin();
	ChangeOption(0);
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
	InitSecondScreen(_hud);
	SetupOption();
	GetGameMode()->GetHUD()->AddToViewport(canvas);
}

void MainMenu::InitSecondScreen(HUD* _hud)
{
	ImageWidget* _secondBackGround = _hud->SpawnWidget<ImageWidget>(RectangleShapeData(GetWindowSize(), "Ui/Menu/Table", JPG));
	canvas->AddChild(_secondBackGround);
	_secondBackGround->SetZOrder(0);

	ImageWidget* _book = _hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(800.0f, 541.4f), "Ui/Menu/Book"));
	canvas->AddChild(_book);
	_book->SetOriginAtMiddle();
	_book->SetPosition(Vector2f(GetWindowSize().x / 2.0f - 100.0f, GetWindowSize().y / 2.0f));
	_book->Rotate(degrees(30.0f));
	_book->SetZOrder(1);

	LabelWidget* _campaign = _hud->SpawnWidget<LabelWidget>("CAMPAGNE");
	canvas->AddChild(_campaign);
	_campaign->SetFont("Overcooked", TTF);
	_campaign->SetFillColor(Color(77, 88, 105));
	//_campaign->SetOriginAtMiddle();
	_campaign->SetPosition(Vector2f(GetWindowSize().x * 0.49f, GetWindowSize().y * 0.4f));
	_campaign->SetZOrder(2);

	LabelWidget* _quit = _hud->SpawnWidget<LabelWidget>("QUITTER");
	canvas->AddChild(_quit);
	_quit->SetFont("Overcooked", TTF);
	//_quit->SetOriginAtMiddle();
	_quit->SetFillColor(Color(77, 88, 105));
	_quit->SetPosition(Vector2f(GetWindowSize().x * 0.49f, GetWindowSize().y * 0.55f));
	_quit->SetZOrder(2);

	ImageWidget* _option1 = _hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(22.5f, 22.5f), "Ui/Menu/Arrow"));
	canvas->AddChild(_option1);
	//_option1->SetOriginAtMiddle();
	_option1->SetPosition(Vector2f(GetWindowSize().x * 0.45f, GetWindowSize().y * 0.405f));
	_option1->SetZOrder(2);


	ImageWidget* _option2 = _hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(22.5f, 22.5f), "Ui/Menu/Arrow"));
	canvas->AddChild(_option2);
	//_option2->SetOriginAtMiddle();
	_option2->SetPosition(Vector2f(GetWindowSize().x * 0.45f, GetWindowSize().y * 0.555f));
	_option2->SetZOrder(2);

	// Second Screen vector
	secondScreen.push_back(_book);
	secondScreen.push_back(_secondBackGround);
	secondScreen.push_back(_campaign);
	secondScreen.push_back(_quit);
	secondScreen.push_back(_option1);
	secondScreen.push_back(_option2);

	thirdScreen.push_back(_book);
	thirdScreen.push_back(_secondBackGround);

	// option Vector
	choices.push_back(_option1);
	choices.push_back(_option2);
}

void MainMenu::ChooseScreen()
{
	if ((*currentChoice) == choices[0])
	{
		ChooseMapLevel* _mainMenu = new ChooseMapLevel();
		M_LEVEL.SetLevel(_mainMenu);
		return;
	}
	else if ((*currentChoice) == choices[1])
	{
		Exit();
	}
	//TODO Option
	//TODO Credits
}

void MainMenu::ChooseChoices(const int _index)
{
	//NE PAS FAIRE DE SECURITY

	ChangeOption(_index);
}

// NE PAS LIRE THOMAS
void MainMenu::Exit()
{
	Unload();
}


