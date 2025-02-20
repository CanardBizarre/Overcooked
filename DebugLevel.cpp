#include "DebugLevel.h"
#include "WorkPlan.h"
#include "TestDummy.h"
#include "LevelLoader.h"
#include "FileManager.h"
using namespace File;

DebugLevel::DebugLevel() : GameplayLevel("Debug")
{
	player = nullptr;
}

void DebugLevel::InitLevel()
{
	Super::InitLevel();

	const string& _folders = "LevelsData/";
	const string& _path = _folders + "DebugLevel";

	const vector<string>& _texts = M_FILE.ReadFile(_path.c_str());

	M_LEVELLOADER.InterpretString(_texts);


	FoodSpawner* _spawner = SpawnActor<FoodSpawner>(Vector2f(50.0f, 50.0f), 
		Vector2f(GetWindowSize() / 2.0f) , Angle(degrees(0)), BT_FOOD_SPAWNER, "IngredientSpawner");

	Ingredient* appleSpawner = _spawner->SpawnIngredient(IT_TORTILLA, IS_RAW, "Tortilla");
}
