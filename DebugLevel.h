#pragma once
#include "GameplayLevel.h"
#include "PlayerPawn.h"
using namespace Camera;

class DebugLevel : public GameplayLevel
{

public:
	DebugLevel();

protected:
	virtual void InitLevel() override;
};

