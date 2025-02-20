#pragma once
#include "Chronometer.h"
#include "GIFWidget.h"

using namespace UI;
class ScoreWidget : public CanvasWidget
{
	Chronometer* chrono;
	ImageWidget* slide;
	LabelWidget* scoreLabel;
	LabelWidget* comboLabel;
	ImageWidget* coin;
	int score;
	int combo;

public:
	FORCEINLINE bool IsCanceled() const
	{
		return chrono->IsEnd();
	}

	FORCEINLINE int RemoveScore(int _score)
	{
		score -= _score;
		if (score < 0) score = 0;
	}

	FORCEINLINE int AddScore(int _score)
	{
		score += _score * (1+combo);
		if (score > 9999) score = 9999;
	}

	FORCEINLINE int IncrementCombo()
	{
		combo++;
		if (combo > 4) combo = 4;
	}

	FORCEINLINE int ResetCombo()
	{
		combo = 0;
	}



public:
	ScoreWidget(Level* _level, HUD* _hud, const string& _name = "Scores");
	ScoreWidget(const ScoreWidget& _other);
	~ScoreWidget();

public:
	virtual void Tick(const float _deltaTime) override;

};