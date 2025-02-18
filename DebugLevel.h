#pragma once
#include "Level.h"
#include "PlayerPawn.h"
using namespace Camera;

class DebugLevel :  public Level
{
	PlayerPawn* player;
	float gravity;

public:
	FORCEINLINE float GetGravity() const
	{
		return gravity;
	}
	FORCEINLINE void SetGravity(const float _gravity)
	{
		gravity = _gravity;
	}

public:
	DebugLevel();

protected:
	virtual void InitLevel() override;
};

