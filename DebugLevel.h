#pragma once
#include "Level.h"
#include "PlayerPawn.h"
using namespace Camera;

class DebugLevel :  public Level
{
	PlayerPawn* player;

public:
	DebugLevel();

protected:
	virtual void InitLevel() override;
};

