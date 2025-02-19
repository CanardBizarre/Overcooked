#pragma once
#include "Chronometer.h"
#include "CanvasWidget.h"
#include "ImageWidget.h"
#include "ImageWidget.h"
#include "MeshActor.h"
#include "LabelWidget.h"
#include "TimerManager.h"

class CustomChrono : Widget
{
	Chronometer* chrono;
	LabelWidget* label;
	ImageWidget* image;

public :
	FORCEINLINE Chronometer* GetChrono()
	{
		return chrono;
	}
	FORCEINLINE LabelWidget* GetLabel()
	{
		return label;
	}
	FORCEINLINE ImageWidget* GetImage()
	{
		return image;
	}
	
public:
	CustomChrono(Level* _level, const float _time);
	~CustomChrono();

public:
	virtual void Render(RenderWindow& _window);
	void InitChrono();
};

