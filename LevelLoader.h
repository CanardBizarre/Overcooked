#pragma once
#include "Singleton.h"
#include "CoreMinimal.h"
#include "Level.h"

class LevelLoader : public Singleton<LevelLoader>
{
public:
	LevelLoader();

public:
	void InterpretString(const vector<string>& _info);
};