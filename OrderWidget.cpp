#include "OrderWidget.h"
#include "Level.h"
#include "TimerManager.h"

OrderWidget::OrderWidget(Level* _level, HUD* _hud, const DishType& _dishType, vector<IngredientType> _ingredient, const string& _name, const float _time)
	:CanvasWidget(_level, _name)
{
	const int _ingredientSize = CAST(int, _ingredient.size());
	const int _offSet = 50.0f;
	size.x = _offSet * _ingredientSize / 1.75f;
	size.y = 77.0f;
	hud = _hud;

	progressBar = hud->SpawnWidget<ProgressBarWidget>(PT_LEFT, RectangleShapeData(Vector2f(size.x, 10.0f), "/UI/progress_bar"), _time * _ingredientSize);
	progressBar->SetZOrder(21);
	progressBar->SetPosition({ 100.0f, 100.0f });
	progressBar->GetForeground()->SetFillColor(Color::Green);
	AddChild(progressBar);

	dish = hud->SpawnWidget<DishWidget>(_dishType);
	AddChild(dish);
	dish->SetPosition(dish->GetPosition() + Vector2f(size.x / 2.0f, 20.0f));
	dish->SetZOrder(22);


	for (IngredientType _currentType : _ingredient)
	{
		IngredientWidget* _ingredientWidget = hud->SpawnWidget<IngredientWidget>(_currentType);
		AddChild(_ingredientWidget);
		ingredient.push_back(_ingredientWidget);
		_ingredientWidget->SetZOrder(23);
	}
	ComputeIngredientPos();


	chrono = new Chronometer(_time * _ingredientSize);

	timer = new Timer([&]()
		{
			chrono->DecrementCurrentTime();
			progressBar->SetValue(chrono->GetCurrentTime());
			if (IsCanceled())
			{
				timer->Stop();
				callbacks(this);
				isUsed = false;
			}

		}, seconds(1), false, true);

	isUsed = true;
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
	if (chrono->GetCurrentTime() < ((chrono->GetMaxTime() * 2) / 3))
		progressBar->GetForeground()->SetFillColor(Color::Yellow);
	if (chrono->GetCurrentTime() < chrono->GetMaxTime() / 3)
		progressBar->GetForeground()->SetFillColor(Color::Red);

}

void OrderWidget::Reuse(const DishType& _dish, const vector<IngredientType>& _ingredients)
{
	dish->Reuse(_dish);

	const int _ingredientsWidgets = GetIngredientsWidgetSize();
	const int _diff = CAST(int, ingredient.size()) - _ingredientsWidgets;
	if (_diff == 0)
	{
		ReuseAllIngredientWidget(_ingredients);
	}

	else if (_diff > 0)
	{
		for (int _index = 0; _index < _diff; _index++)
		{
			IngredientWidget* _ingredientWidget = hud->SpawnWidget<IngredientWidget>(IT_COUNT);
			AddChild(_ingredientWidget);
			ingredient.push_back(_ingredientWidget);
			_ingredientWidget->SetZOrder(23);
		}
		ComputeIngredientPos();
	}

	else if (_diff < 0)
	{
		ComputeIngredientPos(_ingredients);
	}

}

void OrderWidget::ComputeIngredientPos()
{
	int _index = 0;
	float _lastPos = 15.0f;
	for (IngredientWidget* _widget : ingredient)
	{
		const Vector2f& _size = _widget->GetSize();
		_widget->SetPosition(Vector2f(_lastPos, 62.0f));
		_lastPos = _lastPos + _size.x + 0.5f * ingredient.size() + 5.0f;
		_index++;
	}
}

void OrderWidget::ComputeIngredientPos(const vector<IngredientType>& _ingredients)
{
	for (IngredientWidget* _currentWidget : ingredient)
	{
		_currentWidget->SetPosition(Vector2f(1000.0f, 1000.0f));
	}
	float _lastPos = 15.0f;
	const int _ingredientsWidgets = CAST(int, _ingredients.size());
	for (int _index = 0; _index < _ingredientsWidgets; _index++)
	{
		IngredientWidget* _widget = ingredient[_index];
		_widget->Reuse(_ingredients[_index]);

		const Vector2f& _size = _widget->GetSize();
		_widget->SetPosition(Vector2f(_lastPos + 30.0f, 62.0f));
		_lastPos = _lastPos + _size.x + 30.0f;

	}
}