#pragma once
#include "Level.h"
class DebugLevel :  public Level
{
public:
	DebugLevel();

protected:
	virtual void InitLevel();
};

