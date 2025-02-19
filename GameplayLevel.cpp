#include "GameplayLevel.h"
#include "TestDummy.h"

#include "IngredientWidget.h"
#include "RecipeWidget.h"

GameplayLevel::GameplayLevel(const string& _name) : Level(_name)
{
}

void GameplayLevel::InitLevel()
{
	Super::InitLevel();
	//_dummy->GetMesh()->SetOriginAtMiddle();
	//_dummy->SetPosition((Vector2f(window.getSize()) / 2.0f) + Vector2f(10.0f, 0.0f));

	HUD* _hud = GetGameMode()->GetHUD();

	canvas = _hud->SpawnWidget<CanvasWidget>();
	canvas->SetDebugMode(true);
	canvas->SetSize(CAST(Vector2f, GetWindowSize()));

	//IngredientWidget* _ingredient = _hud->SpawnWidget<IngredientWidget>(IngredientType::IT_BACON);
	//canvas->AddChild(_ingredient);

	vector<IngredientType> _ingredients = { IT_APPLE, IT_BACON, IT_BANANA, IT_BANANA };
	RecipeWidget* _recipe = _hud->SpawnWidget<RecipeWidget>(_hud, _ingredients);

	canvas->AddChild(_recipe);
	_recipe->SetPosition(Vector2f(window.getSize()) / 2.0f);

	/*player1 = SpawnActor<PlayerPawn>();
	player1->SetPosition(Vector2f(window.getSize()) / 2.0f);*/

	GetGameMode()->GetHUD()->AddToViewport(canvas);
}
