#pragma once
#include "CanvasWidget.h"
#include "ImageWidget.h"
#include "LabelWidget.h"
#include "CoreMinimal.h"

class Chronometer
{
	int timerCount;
	int currentTime;
	string time;

public:
	FORCEINLINE int GetCurrentTime()
	{
		return currentTime;
	}
	
	FORCEINLINE void DecrementCurrentTime()
	{
		if (currentTime <= 0) return;
		--currentTime;
	}
	FORCEINLINE string GetTime()
	{
		ComputeTime();
		return time;
	}

	Chronometer(const int _minutes, const int _seconds);
	Chronometer(const int _seconds);

private:
	void ComputeTime();
	void ResetTime();
};