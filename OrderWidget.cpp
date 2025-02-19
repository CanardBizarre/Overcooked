#include "OrderWidget.h"
#include "Level.h"
#include "TimerManager.h"

OrderWidget::OrderWidget(Level* _level, HUD* _hud, vector<IngredientType> _ingredient, const float _time)
	:VerticalBox(_level, BoxData(Vector2f(_time * CAST(int, _ingredient.size()), 85.0f), 15.0f))
{
	const int _ingredienSize = CAST(int,_ingredient.size());

	progressBar = _hud->SpawnWidget<ProgressBarWidget>(PT_LEFT, RectangleShapeData(Vector2f(_time * _ingredienSize / 1.75f, 10.0f), "/UI/progress_bar"), _time);
	progressBar->GetForeground()->SetFillColor(Color::Green);
	AddWidget(progressBar);


	HorizontalBox* _ingredients = _hud->SpawnWidget<HorizontalBox>(BoxData(Vector2f(_time * 2.0f, 85.0f), 15.0f));
	for (IngredientType _currentType : _ingredient)
	{
		IngredientWidget* _ingredientWidget = _hud->SpawnWidget<IngredientWidget>(_currentType);
		_ingredients->AddWidget(_ingredientWidget);
	}

	AddWidget(_ingredients);

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
	:VerticalBox(_other)
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
