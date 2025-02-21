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

class MainMenu : public Level
{
	using IteratorOption = vector<Widget*>::iterator;
	using IteratorAllScreen = map<ScreenType, vector<Widget*>>::iterator;

	CanvasWidget* canvas;

	map<ScreenType, vector<Widget*>> allScreen;
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
		return currentChoice == --choices.end();
	}
	FORCEINLINE bool IsFirstChoice()
	{
		return currentChoice == choices.begin();
	}

public:
	MainMenu();
	virtual ~MainMenu();

private:
	void ChangeOption(const int _index);
	void SetupOption();


public:
	virtual void InitLevel() override;
	// init de tous les widgets des screens
	void InitSecondScreen(HUD* _hud);

	void ChooseScreen();
	void ChooseChoices(const int _index);
	void Exit();


};

