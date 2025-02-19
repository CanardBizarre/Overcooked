#pragma once
#include "ImageWidget.h"
#include "LabelWidget.h"
#include "CanvasWidget.h"
#include "HUD.h"

using namespace UI;

class Score 
{
	LabelWidget* scoreLabel;
	LabelWidget* addLabel;
	ImageWidget* coin;
	CanvasWidget* canvasScore;
	int score;
	HUD* hud;

public:
	Score(HUD* _hud);

	void InitScore(const Vector2f& _windowSize);
	void AddScore(const int _offset);
};

