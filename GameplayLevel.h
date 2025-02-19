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
	float time;
	int currentScore;
	int maxScore;

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
	GameplayLevel(const string& _name, const float _time = 180.0f, const int _maxScore = 60);
	

protected:
	virtual void InitLevel() override;
	void InitWidget(const float _time);

};

