#pragma once

#include "Level.h"
#include "TESTGameMode.h"
#include "PlayerPawn.h"

class TESTLevel : public Level
{
	string path;
	string bgPath;
	PlayerPawn* player;
public:
	FORCEINLINE virtual TESTGameMode* GetGameModeRef() override
	{
		return new TESTGameMode(this);
	}

public:
	TESTLevel(const string& _name = "TestLevel");

protected:
	virtual void InitLevel() override;
};

