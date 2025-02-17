#include "TESTLevel.h"
#include "FileManager.h"
#include "LevelLoader.h"

using namespace File;

TESTLevel::TESTLevel(const string& _name) : Level(_name)
{
	const string& _folders = "LevelsData/";
	path = _folders + "Level_1-1";
}

void TESTLevel::InitLevel()
{
	const vector<string>& _texts = M_FILE.ReadFile(path.c_str());
	M_LEVELLOADER.InterpretString(_texts);
	/*for(string _text : _texts)
	{
		LOG(Display, _text);
	}*/
}
