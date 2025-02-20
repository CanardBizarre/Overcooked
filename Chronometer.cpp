#include "Chronometer.h"

Chronometer::Chronometer(const int _minutes, const int _seconds)
{
	maxTime = (_minutes * 60) + _seconds;
	timerCount = maxTime;
	currentTime = timerCount;
	time = "";

}

Chronometer::Chronometer(const int _seconds)
{
	maxTime = _seconds;
	timerCount = maxTime;
	currentTime = timerCount;
	time = "";
}

void Chronometer::ComputeTime()
{
	const int _minutes = currentTime / 60;
	const int _seconds = currentTime % 60;
	string _isUnderTenMinutes = _minutes < 10 ? "0" : "";
	string _isUnderTenSeconds = _seconds < 10 ? "0" : "";
	const string& _finalText = _isUnderTenMinutes + to_string(_minutes) + ":" + _isUnderTenSeconds + to_string(_seconds);
	time = _finalText;
}

void Chronometer::ResetTime()
{
	currentTime = timerCount;
}