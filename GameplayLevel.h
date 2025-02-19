#pragma once

#include "Level.h"
#include "PlayerPawn.h"
#include "CanvasWidget.h"
#include "Chronometer.h"
using namespace Camera;

class GameplayLevel : public Level
{
	CanvasWidget* canvas; 
	PlayerPawn* player1;
	PlayerPawn* player2;
	Chronometer* chrono;
	LabelWidget* label;
	LabelWidget* scoreLabel;
	ImageWidget* coin;
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
	~GameplayLevel();
	

protected:
	virtual void InitLevel() override;
	void InitWidgetForChrono(HUD* _hud, const float _time);
	void InitScore(HUD* _hud);
	void AddScore(const int _scoreToAdd);
};

