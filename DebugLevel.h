#pragma once
#include "Level.h"
#include "Chronometer.h"
#include "PlayerPawn.h"
using namespace Camera;

class DebugLevel :  public Level
{
	PlayerPawn* player;
	Chronometer* chrono;
	LabelWidget* label;
public:
	DebugLevel();
	~DebugLevel();
protected:
	virtual void InitLevel() override;
};

