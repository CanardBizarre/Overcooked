#pragma once
#include "Chronometer.h"
#include "CanvasWidget.h"
#include "ImageWidget.h"
#include "CustomWidget.h"
#include "ImageWidget.h"
#include "MeshActor.h"
#include "LabelWidget.h"
#include "TimerManager.h"

class CustomChrono
{
	Chronometer* chrono;
	LabelWidget* label;
	ImageWidget* image;
	CanvasWidget* canvas;

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
	FORCEINLINE CanvasWidget* GetCanvas()
	{
		return canvas;
	}

public:
	CustomChrono(LabelWidget* _label, ImageWidget* _image, CanvasWidget* _canvas);
	~CustomChrono();

	void InitChrono();
};

