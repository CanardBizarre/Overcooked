#include "Level_1_1.h"

#include "FileManager.h"
#include "LevelLoader.h"
#include "LevelManager.h"

using namespace File;

Level_1_1::Level_1_1() : GameplayLevel("Level 1-1")
{

}

void Level_1_1::InitLevel()
{
	Super::InitLevel();


	const string& _folders = "LevelsData/";
	const string& _path = _folders + "Level_1-1";
	const string& _pathBg = _folders + "BackGround_1-1";

	const vector<string>& _textsBg = M_FILE.ReadFile(_pathBg.c_str());
	const vector<string>& _texts = M_FILE.ReadFile(_path.c_str());

	Level* _level = M_LEVEL.GetCurrentLevel();
	MeshActor* _backGround = _level->SpawnActor<MeshActor>(RectangleShapeData(Vector2f(1435.5, 1138.5), "Blocks/BG1"));
	_backGround->SetPosition(Vector2f(-70, -70));
	_backGround->SetZOrder(0);

	M_LEVELLOADER.InterpretString(_textsBg);
	M_LEVELLOADER.InterpretString(_texts);

	foodSpawners[0]->SetType(IT_LETTUCE);
}
