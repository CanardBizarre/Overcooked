#pragma once
#include "Level.h"
#include "CustomChrono.h"
#include "PlayerPawn.h"
using namespace Camera;

class DebugLevel :  public Level
{
	CustomChrono* chronoWidget;
	HUD* hud;
	PlayerPawn* player;
public:
	DebugLevel();
	~DebugLevel();
protected:
	virtual void InitLevel() override;
};

