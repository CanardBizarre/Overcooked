#pragma once
#include "Level.h"
#include "ChooseMapPawn.h"

class ChooseMapLevel : public Level
{
	ChooseMapPawn* player;
public:

public:
	ChooseMapLevel();
	virtual ~ChooseMapLevel();
public:

	virtual void InitLevel() override;

};

