#include "TESTLevel.h"
#include "FileManager.h"
#include "LevelLoader.h"
#include "MeshActor.h"

using namespace File;

TESTLevel::TESTLevel(const string& _name) : Level(_name)
{
	const string& _folders = "LevelsData/";
	path = _folders + "Level_1-1";
	bgPath = _folders + "BackGround_1-1";
}

void TESTLevel::InitLevel()
{
	Super::InitLevel();

	const vector<string>& _textBg = M_FILE.ReadFile(bgPath.c_str());
	M_LEVELLOADER.InterpretString(_textBg);
	const vector<string>& _texts = M_FILE.ReadFile(path.c_str());
	M_LEVELLOADER.InterpretString(_texts);
	
	player = SpawnActor<PlayerPawn>();
	player->SetPosition(Vector2f(window.getSize()) / 2.0f);
}
