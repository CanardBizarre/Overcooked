#include "DebugLevel.h"
#include "WorkPlan.h"
#include "TestDummy.h"
#include "LevelLoader.h"
#include "FileManager.h"
#include "FoodSpawner.h"

using namespace File;

DebugLevel::DebugLevel() : GameplayLevel("DebugLevel")
{
}

void DebugLevel::InitLevel()
{
	Super::InitLevel();

	const string& _folders = "LevelsData/";
	const string& _path = _folders + "DebugLevel";

	const vector<string>& _texts = M_FILE.ReadFile(_path.c_str());

	M_LEVELLOADER.InterpretString(_texts);

	for (FoodSpawner* _foodSpawner : foodSpawners)
	{
		_foodSpawner->SetType(IT_MUSHROOM);
	}

	//Ingredient* appleSpawner = _spawner->SpawnIngredient(IT_TORTILLA, "Tortilla");
}
