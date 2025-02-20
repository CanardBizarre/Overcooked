#pragma once
#include "GameplayLevel.h"
#include "PlayerPawn.h"
using namespace Camera;

class DebugLevel : public GameplayLevel
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
	virtual ~DebugLevel(){}
protected:
	virtual void InitLevel() override;
};

