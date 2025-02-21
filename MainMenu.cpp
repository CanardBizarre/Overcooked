#include "MainMenu.h"

#include "MainMenuPlayerController.h"
#include "MainMenuPawn.h"
#include "MainMenuHUD.h"

#include "DebugLevel.h"
#include "Level_1_1.h"
#include "Level_2_1.h"
#include "Level_3_1.h"
#include "Level_4_1.h"
#include "Level_5_1.h"

#include "LevelManager.h"


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
		for (int _index = 0; _index < _increment; _index++) currentScreen++;

	}
	else
	{
		for (int _index = 0; _index > _increment; _index--) currentScreen--;
	}

	for (pair<ScreenType, vector<Widget*>> _currentScreen : allScreen)
	{
		for (Widget* _currentWidget : _currentScreen.second)
		{
			_currentWidget->SetVisibility(Hidden);
		}
	}
	
	for (Widget* _currentWidget : (*currentScreen).second)
	{
		_currentWidget->SetVisibility(Visible);
	}
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
	else if(_increment < 0)
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

void MainMenu::SetupFirstScreen()
{
	allScreen.insert(make_pair(ST_FIRST, firstScreen));
	allScreen.insert(make_pair(ST_SECOND, secondScreen));
	allScreen.insert(make_pair(ST_CAMPAIGN, thirdScreen));

	currentScreen = allScreen.begin();
	ChangeScreen(0);
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
	InitFirstScreen(_hud);
	InitSecondScreen(_hud);
	InitCampaign(_hud);

	SetupOption();
	SetupFirstScreen();

	GetGameMode()->GetHUD()->AddToViewport(canvas);
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
	_book->SetPosition(Vector2f(GetWindowSize().x / 2.0f - 100.0f, GetWindowSize().y / 2.0f));
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


	ImageWidget* _option1 = _hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(22.5f, 22.5f), "Ui/Menu/Arrow"));
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

	thirdScreen.push_back(_book);
	thirdScreen.push_back(_secondBackGround);

	// option Vector
	choices.push_back(_option1);
	choices.push_back(_option2);
	choices.push_back(_option3);


}

void MainMenu::InitCampaign(HUD* _hud)
{
	LabelWidget* _continue = _hud->SpawnWidget<LabelWidget>("CONTINUE");
	canvas->AddChild(_continue);
	_continue->SetFont("segoe-ui-black", TTF);
	_continue->SetFillColor(Color(77, 88, 105));
	_continue->SetPosition(Vector2f(GetWindowSize().x * 0.5f, GetWindowSize().y * 0.2f));
	_continue->SetZOrder(2);

	LabelWidget* _newGame = _hud->SpawnWidget<LabelWidget>("NEW GAME");
	canvas->AddChild(_newGame);
	_newGame->SetFont("segoe-ui-black", TTF);
	_newGame->SetFillColor(Color(77, 88, 105));
	_newGame->SetPosition(Vector2f(GetWindowSize().x * 0.5f, GetWindowSize().y * 0.3f));
	_newGame->SetZOrder(2);

	thirdScreen.push_back(_continue);
	thirdScreen.push_back(_newGame);
}

void MainMenu::ChooseScreen(const int _index)
{
	if ((*currentScreen).first == ST_FIRST && _index < 0) return;
	if ((*currentScreen).first == ST_CAMPAIGN)
	{
		Level_1_1* _mainMenu = new Level_1_1();
		M_LEVEL.SetLevel(_mainMenu);
		return;
	}

	ChangeScreen(_index);
	ChangeOption(0);
}

void MainMenu::ChooseChoices(const int _index)
{
	if ((*currentScreen).first == ST_SECOND)
	{
		ChangeOption(_index);
	}
	if ((*currentScreen).first == ST_CAMPAIGN)
	{
		ChangeOption(_index);
	}
}


