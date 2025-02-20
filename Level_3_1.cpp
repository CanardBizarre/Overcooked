#include "Level_3_1.h"

#include "FileManager.h"
#include "LevelLoader.h"

using namespace File;

Level_3_1::Level_3_1() : GameplayLevel("Level 3-1")
{

}

void Level_3_1::InitLevel()
{
	Super::InitLevel();

	const string& _folders = "LevelsData/";
	const string& _path = _folders + "Level_3-1";
	const string& _pathBg = _folders + "BackGround_3-1";

	const vector<string>& _textsBg = M_FILE.ReadFile(_pathBg.c_str());
	const vector<string>& _texts = M_FILE.ReadFile(_path.c_str());

	M_LEVELLOADER.InterpretString(_textsBg);
	M_LEVELLOADER.InterpretString(_texts);
}
