#include "OrderWidget.h"
#include "Level.h"
#include "TimerManager.h"

OrderWidget::OrderWidget(Level* _level, HUD* _hud, const DishType& _dishType, vector<IngredientType> _ingredient, const string& _name, const float _time)
	:CanvasWidget(_level, _name)
{
	const int _ingredientSize = CAST(int,_ingredient.size());

	progressBar = _hud->SpawnWidget<ProgressBarWidget>(PT_LEFT, RectangleShapeData(Vector2f(100.0f, 10.0f), "/UI/progress_bar"), _time);
	progressBar->SetZOrder(10);
	progressBar->SetPosition({ 100.0f, 100.0f });
	progressBar->GetForeground()->SetFillColor(Color::Green);
	AddChild(progressBar);

	DishWidget* _dishWidget = _hud->SpawnWidget<DishWidget>(_dishType);
	AddChild(_dishWidget);
	_dishWidget->SetPosition(Vector2f(48.0f,30.0f));
	_dishWidget->SetZOrder(9);

	for (IngredientType _currentType : _ingredient)
	{
		const int _ingredientSize = CAST(int, ingredient.size());
		IngredientWidget* _ingredientWidget = _hud->SpawnWidget<IngredientWidget>(_currentType);
		AddChild(_ingredientWidget);
		_ingredientWidget->SetPosition(Vector2f(15.0f + (18.0f * _ingredientSize), 54.0f));
		_ingredientWidget->SetZOrder(9);
		ingredient.push_back(_ingredientWidget);
	}

	slider = _hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(100.0f, 100.0f), "/UI/recipe", PNG));
	AddChild(slider);

	progressBar->SetZOrder(10);
	progressBar->SetPosition({ 10.0f, 10.0f });
	progressBar->GetForeground()->SetFillColor(Color::Green);
	AddChild(progressBar);

	chrono = new Chronometer(_time);
	new Timer([&]() 
	{
			chrono->DecrementCurrentTime(); 
			progressBar->SetValue(chrono->GetCurrentTime());
			if (chrono->GetCurrentTime() < ((chrono->GetMaxTime() * 2) / 3))  progressBar->GetForeground()->SetFillColor(Color::Yellow);
			if (chrono->GetCurrentTime() < chrono->GetMaxTime() / 3)  progressBar->GetForeground()->SetFillColor(Color::Red); 
	}, seconds(1), true, true);
}

OrderWidget::OrderWidget(const OrderWidget& _other)
	:CanvasWidget(_other)
{

}

OrderWidget::~OrderWidget()
{
	delete chrono;
}

void OrderWidget::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);

}
