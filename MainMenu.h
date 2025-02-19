#pragma once
#include "Level.h"
#include "MainMenuGameMode.h"
#include "CanvasWidget.h"
#include "LabelWidget.h"
#include "ImageWidget.h"

enum ScreenType
{
	ST_FIRST,
	ST_CHOICES,
	ST_CAMPAIGN,
	ST_OPTION,
	ST_CREDIT,
};

class MainMenu :  public Level
{
	using IteratorOption = vector<Widget*>::iterator;
	using IteratorAllScreen = vector<vector<Widget*>>::iterator;

	CanvasWidget* canvas;

	vector<	vector<Widget*>> allScreen;
	IteratorAllScreen currentScreen;

	vector<Widget*> firstScreen;
	vector<Widget*> secondScreen;

	vector<Widget*> options;
	IteratorOption currentOption;

public:
	FORCEINLINE virtual MainMenuGameMode* GetGameModeRef() override
	{
		return new MainMenuGameMode(this);
	}


public:
	MainMenu();
	virtual ~MainMenu();

private:
	void ChangeScreen(const int _increment = 1);
	void SetupFirstScreen();

public:
	virtual void InitLevel() override;
	void InitFirstScreen(HUD* _hud);
	void InitSecondScreen(HUD* _hud);


	void ChooseScreen(const ScreenType& _screen);
	
	
};

