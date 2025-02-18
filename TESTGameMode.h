#pragma once

#include "GameMode.h"

class TESTGameMode : public GameMode
{
public:
	TESTGameMode(Level* _level, const string& _name = "GameMode");
	TESTGameMode(const TESTGameMode& _other);
};

