#pragma once
#include "Singleton.h"
#include "CoreMinimal.h"
#include "Level.h"


class LevelLoader : public Singleton<LevelLoader>
{
public:
	FORCEINLINE string GetStringUntilChar(stringstream& _stream, const char _character) const
	{
		string _token = "";
		getline(_stream, _token, _character);
		return _token;
	}
public:
	LevelLoader();

public:
	void InterpretString(const vector<string>& _info);
};