#include "Level_1_1.h"

#include "FileManager.h"
#include "LevelLoader.h"

using namespace File;

Level_1_1::Level_1_1() : GameplayLevel("Level 1-1")
{

}

void Level_1_1::InitLevel()
{
	Super::InitLevel();

	const string& _folders = "LevelsData/";
	const string& _path = _folders + "Level_1-1";

	const vector<string>& _texts = M_FILE.ReadFile(_path.c_str());

	M_LEVELLOADER.InterpretString(_texts);

	foodSpawners[0]->SetType(IT_TOMATO);
}
