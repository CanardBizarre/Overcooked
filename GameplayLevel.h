#pragma once
#include "Level.h"
#include "PlayerPawn.h"
#include "CanvasWidget.h"

using namespace Camera;

class GameplayLevel : public Level
{
	CanvasWidget* canvas; 
	PlayerPawn* player1;
	PlayerPawn* player2;
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
	GameplayLevel(const string& _name);


protected:
	virtual void InitLevel() override;
};

