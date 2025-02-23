#include "Level_3_1.h"

#include "FileManager.h"
#include "LevelLoader.h"
#include "LevelManager.h"

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

	Level* _level = M_LEVEL.GetCurrentLevel();
	MeshActor* _backGround = _level->SpawnActor<MeshActor>(RectangleShapeData(Vector2f(2000, 1200), "Blocks/BG3"));
	_backGround->SetPosition(Vector2f(-100, -110));
	_backGround->SetZOrder(0);

	M_LEVELLOADER.InterpretString(_textsBg);
	M_LEVELLOADER.InterpretString(_texts);


	foodSpawners[0]->SetType(IT_RICE);
	foodSpawners[1]->SetType(IT_FISH);
	foodSpawners[2]->SetType(IT_CUCUMBER);
	foodSpawners[3]->SetType(IT_SEAWEED);

}
