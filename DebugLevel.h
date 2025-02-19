#pragma once
#include "Level.h"
#include "GameplayLevel.h"
#include "PlayerPawn.h"
using namespace Camera;

class DebugLevel : public GameplayLevel
{
	HUD* hud;
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
	~DebugLevel();
protected:
	virtual void InitLevel() override;
};

