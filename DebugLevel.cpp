#include "DebugLevel.h"
#include "WorkPlan.h"

#include "TestDummy.h"
#include "LevelLoader.h"
#include "FileManager.h"
using namespace File;

DebugLevel::DebugLevel() : GameplayLevel("Debug")
{
	player = nullptr;
}

void DebugLevel::InitLevel()
{
	Super::InitLevel();

	const string& _folders = "LevelsData/";
	const string& _path = _folders + "DebugLevel";

	const vector<string>& _texts = M_FILE.ReadFile(_path.c_str());

	M_LEVELLOADER.InterpretString(_texts);
}
