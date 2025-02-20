#include "DebugLevel.h"
#include "TestDummy.h"
#include "WorkPlan.h"
#include "FoodSpawner.h"
DebugLevel::DebugLevel() : Level("Debug")
{

}

void DebugLevel::InitLevel()
{
	Super::InitLevel();

	FoodSpawner* _spawner = SpawnActor<FoodSpawner>(Vector2f(50.0f, 50.0f), 
		Vector2f(GetWindowSize() / 2.0f) , Angle(degrees(0)), BT_FOOD_SPAWNER, "IngredientSpawner");

	Ingredient* appleSpawner = _spawner->SpawnIngredient(IT_TORTILLA, IS_RAW, "Tortilla");

	TestDummy* _dummy = SpawnActor<TestDummy>();
	_dummy->GetMesh()->SetOriginAtMiddle();
	_dummy->SetPosition((Vector2f(window.getSize()) / 2.0f) + Vector2f(10.0f, 0.0f));

	player = SpawnActor<PlayerPawn>();
	player->SetPosition(Vector2f(window.getSize()) / 2.0f);
}
