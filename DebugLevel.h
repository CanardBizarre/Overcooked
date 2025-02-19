#pragma once
#include "Level.h"
#include "CustomChrono.h"
#include "PlayerPawn.h"
#include "CanvasWidget.h"
#include "RecipeWidget.h"
using namespace Camera;

class DebugLevel :  public Level
{
	CustomChrono* chronoWidget;
	vector<RecipeWidget*> recipe;
	CanvasWidget* canva;
	HUD* hud;
	PlayerPawn* player;
public:
	DebugLevel();
	~DebugLevel();
protected:
	virtual void InitLevel() override;
};

