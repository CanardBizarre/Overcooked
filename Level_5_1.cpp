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
	MeshActor* _backGround = _level->SpawnActor<MeshActor>(RectangleShapeData(Vector2f(2326.8f, 1305.6f), "Blocks/BG5"));
	_backGround->SetPosition(Vector2f(-420, -108));
	_backGround->SetZOrder(0);

	M_LEVELLOADER.InterpretString(_texts);

	foodSpawners[0]->SetType(IT_MEAT);
	foodSpawners[1]->SetType(IT_MUSHROOM);
	foodSpawners[2]->SetType(IT_RICE);
	foodSpawners[3]->SetType(IT_TORTILLA);

}
