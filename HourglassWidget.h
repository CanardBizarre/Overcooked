#pragma once
#include "Chronometer.h"

using namespace UI;
class HourglassWidget : public CanvasWidget
{
	Chronometer* chrono;
	ImageWidget* hourglass;
	ImageWidget* slide;
	LabelWidget* label;
	function<void()> callback;

public:
	FORCEINLINE bool IsCanceled() const
	{
		return chrono->IsEnd();
	}
	FORCEINLINE void SetCallBack(function<void()> _callback)
	{
		callback = _callback;
	}
public:
	HourglassWidget(Level* _level, HUD* _hud, const string& _name = "Hourglass", const float _time = 90.0f);
	HourglassWidget(const HourglassWidget& _other);
	~HourglassWidget();

public:
	virtual void Tick(const float _deltaTime) override;

};
