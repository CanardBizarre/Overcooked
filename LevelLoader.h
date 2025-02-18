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
	FORCEINLINE bool HasFoundSymbolInLine(const string& _line, const char _character) const
	{
		stringstream _stream = stringstream(_line);

		string _token = "";

		getline(_stream, _token);

		for (char _char : _token)
		{
			if (_char == _character) return true;
		}
		return false;
	}
public:
	LevelLoader();

public:
	void InterpretString(const vector<string>& _info);
};