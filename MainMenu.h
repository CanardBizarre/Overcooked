#pragma once
#include "Level.h"
#include "MainMenuGameMode.h"
#include "CanvasWidget.h"
#include "LabelWidget.h"
#include "ImageWidget.h"

class MainMenu :  public Level
{
	CanvasWidget* canvas;
	vector<Widget*> firstScreen;

public:
	FORCEINLINE virtual MainMenuGameMode* GetGameModeRef() override
	{
		return new MainMenuGameMode(this);
	}

public:
	MainMenu();

public:
	virtual void InitLevel() override;
	void InitFirstScreen(HUD* _hud);
	
	
};

