#include "Level_4_1.h"

#include "FileManager.h"
#include "LevelLoader.h"

using namespace File;

Level_4_1::Level_4_1() : GameplayLevel("Level 4-1")
{

}

void Level_4_1::InitLevel()
{
	Super::InitLevel();

	const string& _folders = "LevelsData/";
	const string& _path = _folders + "Level_4-1";

	const vector<string>& _texts = M_FILE.ReadFile(_path.c_str());

	M_LEVELLOADER.InterpretString(_texts);

	foodSpawners[0]->SetType(IT_MUSHROOM);
	foodSpawners[1]->SetType(IT_CHICKEN);
	foodSpawners[2]->SetType(IT_TOMATO);

}
