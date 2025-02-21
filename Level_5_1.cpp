#include "Level_5_1.h"

#include "FileManager.h"
#include "LevelLoader.h"

using namespace File;

Level_5_1::Level_5_1() : GameplayLevel("Level 5-1")
{

}

void Level_5_1::InitLevel()
{
	Super::InitLevel();

	const string& _folders = "LevelsData/";
	const string& _path = _folders + "Level_5-1";

	const vector<string>& _texts = M_FILE.ReadFile(_path.c_str());

	M_LEVELLOADER.InterpretString(_texts);

	foodSpawners[0]->SetType(IT_MEAT);
	foodSpawners[1]->SetType(IT_TOMATO);
	foodSpawners[2]->SetType(IT_LETTUCE);
	foodSpawners[3]->SetType(IT_TORTILLA);

}
