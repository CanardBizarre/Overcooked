#pragma once
#include "CanvasWidget.h"
#include "ImageWidget.h"
#include "LabelWidget.h"
#include "CoreMinimal.h"

class Chronometer
{
	int timerCount;
	int currentTime;
	int maxTime;
	string time;

public:
	FORCEINLINE bool IsEnd() const
	{
		return currentTime == 0;
	}

	FORCEINLINE int GetCurrentTime()
	{
		return currentTime;
	}

	FORCEINLINE void DecrementCurrentTime()
	{
		if (currentTime <= 0) return;
		--currentTime;
	}

	FORCEINLINE int GetMaxTime()
	{
		return maxTime;
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