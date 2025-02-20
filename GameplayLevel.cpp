#include "GameplayLevel.h"
#include "TestDummy.h"
#include "IngredientWidget.h"
#include "TimerManager.h"
#include "Box.h"



GameplayLevel::GameplayLevel(const string& _name) : Level(_name)
{
}

void GameplayLevel::ComputeOrdersPos()
{
	int _index = 0;
	float _lastPos = 0;
	for (OrderWidget* _widget : orders)
	{
		if (_widget->IsUsedState())
		{
			const Vector2f& _size = _widget->GetSize();
			_widget->SetPosition(Vector2f(_lastPos + 15.0f, 0.0f));
			_lastPos = _lastPos + _size.x + 15.0f;
			_index++;
		}
	}
}

void GameplayLevel::InitLevel()
{
	Super::InitLevel();

	TestDummy* _dummy = SpawnActor<TestDummy>();
	_dummy->GetMesh()->SetOriginAtMiddle();
	_dummy->SetPosition((Vector2f(window.getSize()) / 2.0f) + Vector2f(10.0f, 0.0f));
	_dummy->SetZOrder(1);

	hud = GetGameMode()->GetHUD();

	canvas = hud->SpawnWidget<CanvasWidget>();
	canvas->SetDebugMode(true);
	canvas->SetSize(CAST(Vector2f, GetWindowSize()));

	const vector<IngredientType>& _food = {IT_APPLE, IT_BACON};


	player1 = SpawnActor<PlayerPawn>();
	player1->SetPosition(Vector2f(window.getSize()) / 2.0f);
	player1->SetZOrder(2);

	
	const vector<IngredientType>& _ingredient = { IngredientType::IT_APPLE, IngredientType::IT_BACON };
	MakeOrderWidget(DT_BEEF_BURRITO, _ingredient);
	const vector<IngredientType>& _ingredient2 = { IngredientType::IT_APPLE, IngredientType::IT_BACON, IngredientType::IT_APPLE};
	MakeOrderWidget(DT_BEEF_BURRITO, _ingredient2);
	const vector<IngredientType>& _ingredient3 = { IngredientType::IT_APPLE, IngredientType::IT_BACON, IngredientType::IT_APPLE, IngredientType::IT_APPLE };
	MakeOrderWidget(DT_BEEF_BURRITO, _ingredient3);
		
	hourglass = hud->SpawnWidget<HourglassWidget>(hud, "Hourglass", 90.0f);
	canvas->AddChild(hourglass);

	score = hud->SpawnWidget<ScoreWidget>(hud, "Score");
	canvas->AddChild(score);



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
