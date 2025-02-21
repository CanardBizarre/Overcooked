#include "GameplayLevel.h"
#include "TestDummy.h"
#include "IngredientWidget.h"
#include "TimerManager.h"
#include "Box.h"

GameplayLevel::GameplayLevel(const string& _name) : Level(_name)
{
	gravity = 9.8f;

	hud = nullptr;
	score = nullptr;
	canvas = nullptr;
	hourglass = nullptr;

	player1 = nullptr;
	player2 = nullptr;
}

void GameplayLevel::ComputeOrdersPos()
{
	int _index = 0;
	float _lastPos = 0;
	const float _offset = orders.size() * 0.5f + 15.0f;
	for (OrderWidget* _widget : orders)
	{
		if (_widget->IsUsedState())
		{
			const Vector2f& _size = _widget->GetSize();
			_widget->SetPosition(Vector2f(_lastPos + _offset, 3.0f));
			_lastPos = _lastPos + _size.x + _offset;
			_index++;
		}
	}
}

void GameplayLevel::InitLevel()
{
	Super::InitLevel();
	hud = GetGameMode()->GetHUD();
	const Vector2f& _windozSize = CAST(Vector2f, GetWindowSize());
	canvas = hud->SpawnWidget<CanvasWidget>();
	canvas->SetDebugMode(true);
	canvas->SetSize(_windozSize);


	hourglass = hud->SpawnWidget<HourglassWidget>(hud, "Hourglass");
	canvas->AddChild(hourglass);
	hourglass->SetPosition(_windozSize * 0.8f);

	score = hud->SpawnWidget<ScoreWidget>(hud, "Score");
	canvas->AddChild(score);
	score->SetPosition(Vector2f(_windozSize.x * 0.1f, _windozSize.y * 0.8f));

	player1 = SpawnActor<PlayerPawn>();
	player1->SetPosition(Vector2f(window.getSize()) / 2.0f);
	player1->SetZOrder(20);


	const vector<IngredientType>& _ingredient = { IngredientType::IT_CHICKEN, IngredientType::IT_TORTILLA };
	MakeOrderWidget(DT_SALAD_LETTUCE_AND_TOMATO, _ingredient);
	const vector<IngredientType>& _ingredient2 = { IngredientType::IT_CUCUMBER, IngredientType::IT_FISH, IngredientType::IT_LETTUCE };
	MakeOrderWidget(DT_BEEF_BURRITO, _ingredient2);
	const vector<IngredientType>& _ingredient3 = { IngredientType::IT_MEAT, IngredientType::IT_MUSHROOM, IngredientType::IT_PRAWN, IngredientType::IT_RICE };
	MakeOrderWidget(DT_SUSHI_FISH_AND_PRAWN, _ingredient3);



	GetGameMode()->GetHUD()->AddToViewport(canvas);
}

void GameplayLevel::MakeOrderWidget(const DishType& _dish, const vector<IngredientType>& _ingredients)
{
	for (OrderWidget* _widget : orders)
	{
		if (!_widget->IsUsedState())
		{
			_widget->Reuse(_dish, _ingredients);
			return;
		}

	}

	const int _orderSize = (int)orders.size();

	OrderWidget* _recipe = hud->SpawnWidget<OrderWidget>(hud, _dish, _ingredients, "Order_" + to_string(_orderSize));
	canvas->AddChild(_recipe);
	orders.insert(_recipe);

	function<void(OrderWidget* _this)> _callBacks = [&](OrderWidget* _this)
		{
			_this->SetIsUsedState(false);
			_this->SetPosition(Vector2f(2000.0f, 2000.0f));
			ComputeOrdersPos();
		};

	_recipe->SetCallback(_callBacks);

	_recipe->StartTimer();

	ComputeOrdersPos();

}