#include "Level_5_1.h"

#include "FileManager.h"
#include "LevelLoader.h"
#include "LevelManager.h"

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

	Level* _level = M_LEVEL.GetCurrentLevel();
	MeshActor* _backGround = _level->SpawnActor<MeshActor>(RectangleShapeData(Vector2f(2326.8, 1305.6), "Blocks/BG5"));
	_backGround->SetPosition(Vector2f(-400, -85));

	M_LEVELLOADER.InterpretString(_texts);
}
