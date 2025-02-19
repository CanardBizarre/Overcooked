#include "Level_2_1.h"

#include "FileManager.h"
#include "LevelLoader.h"

using namespace File;

Level_2_1::Level_2_1() : GameplayLevel("Level 2-1")
{

}

void Level_2_1::InitLevel()
{
	Super::InitLevel();

	const string& _folders = "LevelsData/";
	const string& _path = _folders + "Level_2-1";

	const vector<string>& _texts = M_FILE.ReadFile(_path.c_str());

	M_LEVELLOADER.InterpretString(_texts);
}
