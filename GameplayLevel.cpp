#include "GameplayLevel.h"
#include "TestDummy.h"
#include "IngredientWidget.h"
#include "TimerManager.h"
#include "Box.h"



GameplayLevel::GameplayLevel(const string& _name) : Level(_name)
{
}

void GameplayLevel::InitLevel()
{
	Super::InitLevel();
	//_dummy->GetMesh()->SetOriginAtMiddle();
	//_dummy->SetPosition((Vector2f(window.getSize()) / 2.0f) + Vector2f(10.0f, 0.0f));

	hud = GetGameMode()->GetHUD();

	canvas = hud->SpawnWidget<CanvasWidget>();
	canvas->SetDebugMode(true);
	canvas->SetSize(CAST(Vector2f, GetWindowSize()));

	vector<IngredientType> _food = { IngredientType::IT_APPLE, IngredientType::IT_BACON };
	OrderWidget* _recipe = hud->SpawnWidget<OrderWidget>(hud, DT_BEEF_BURRITO, _food, "Order_" + to_string(0));
	canvas->AddChild(_recipe);

	//new Timer([&]()
	//	{
	//	


	//	MakeOrderWidget(DT_BEEF_BURRITO, _food);
	//	}, seconds(1.0f), true, true);

	player1 = SpawnActor<PlayerPawn>();
	player1->SetPosition(Vector2f(window.getSize()) / 2.0f);

	GetGameMode()->GetHUD()->AddToViewport(canvas);
}

void GameplayLevel::MakeOrderWidget(const DishType& _dish, const vector<IngredientType>& _ingredients)
{
	const int _orderSize = (int)_order.size();
	OrderWidget* _recipe = hud->SpawnWidget<OrderWidget>(hud, _dish, _ingredients, "Order_" + to_string(_orderSize));
	orders->AddWidget(_recipe);
}
