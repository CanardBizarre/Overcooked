#pragma once
#include "Level.h"
#include "KeyboardPawn.h"
using namespace Camera;

class DebugLevel :  public Level
{
	KeyboardPawn* player;
public:
	DebugLevel();

protected:
	virtual void InitLevel() override;
};

