#pragma once
#include "Level.h"
#include "MainMenuGameMode.h"
#include "CanvasWidget.h"
#include "LabelWidget.h"
#include "ImageWidget.h"

enum ScreenType
{
	ST_FIRST,
	ST_SECOND,
	ST_CAMPAIGN,
	ST_OPTION,
	ST_CREDIT,
};

class MainMenuLevel :  public Level
{
	using IteratorOption = vector<Widget*>::iterator;
	using IteratorAllScreen = map<ScreenType, vector<Widget*>>::iterator;

	CanvasWidget* canvas;

	map<ScreenType,vector<Widget*>> allScreen;
	IteratorAllScreen currentScreen;

	vector<Widget*> firstScreen;
	vector<Widget*> secondScreen;
	vector<Widget*> thirdScreen;

	vector<Widget*> choices;
	IteratorOption currentChoice;

public:
	FORCEINLINE virtual MainMenuGameMode* GetGameModeRef() override
	{
		return new MainMenuGameMode(this);
	}
	FORCEINLINE bool IsLastChoice()
	{
		return currentChoice == --choices.end() ;
	}
	FORCEINLINE bool IsFirstChoice()
	{
		return currentChoice == choices.begin();
	}

public:
	MainMenuLevel();
	virtual ~MainMenuLevel();

private:
	void ChangeScreen(const int _increment = 1);
	void ChangeOption(const int _index);
	void SetupFirstScreen();
	void SetupOption();


public:
	virtual void InitLevel() override;
	// init de tous les widgets des screens
	void InitFirstScreen(HUD* _hud);
	void InitSecondScreen(HUD* _hud);
	void InitCampaign(HUD* _hud);

	void ChooseScreen(const int _index);
	void ChooseChoices(const int _index);
	
	
};

