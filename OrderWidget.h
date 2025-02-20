#pragma once
#include "VerticalBox.h"
#include "HorizontalBox.h"
#include "IngredientWidget.h"
#include "ProgressBarWidget.h"
#include "Chronometer.h"
#include "DishWidget.h"
#include "TimerManager.h"

using namespace UI;
class OrderWidget : public CanvasWidget
{	
	bool isUsed;
	HUD* hud;
	Chronometer* chrono;
	Timer<Seconds>* timer;
	ProgressBarWidget* progressBar;
	DishWidget* dish;
	vector<IngredientWidget*> ingredient;
	function<void(OrderWidget* _this)> callbacks;
	Vector2f size;


public:
	FORCEINLINE void ReuseAllIngredientWidget(const vector<IngredientType>& _ingredients)
	{
		const int _ingredientsWidgets = GetIngredientsWidgetSize();
		for (int _index = 0; _index < _ingredientsWidgets; _index++)
		{
			ingredient[_index]->Reuse(_ingredients[_index]);
		}
	}
	FORCEINLINE void SetCallback(function<void(OrderWidget* _this)> _callbacks)
	{
		callbacks = _callbacks;
	}

	FORCEINLINE void StartTimer() const
	{
		timer->Start();
	}

	FORCEINLINE void SetIsUsedState(const bool _state)
	{
		isUsed = _state;
	}

	FORCEINLINE bool IsUsedState() const 
	{
		return isUsed;
	}

	FORCEINLINE float GetMaxDuration() const
	{
		return chrono->GetMaxTime();
	}

	FORCEINLINE Vector2f GetSize() const
	{
		return size;
	}

	FORCEINLINE int GetIngredientsWidgetSize() const
	{
		return CAST(int, ingredient.size());
	}

	FORCEINLINE bool IsCanceled() const
	{
		return chrono->IsEnd();
	}

public:	
	OrderWidget(Level* _level, HUD* _hud, const DishType& _dishType, vector<IngredientType> _ingredient, const string& _name = "Orders", const float _time = 25.0f);
	OrderWidget(const OrderWidget& _other);
	~OrderWidget();

public:
	virtual void Tick(const float _deltaTime) override;
	void Reuse(const DishType& _dish, const vector<IngredientType>& _ingredients);
	void ComputeIngredientPos();
	void ComputeIngredientPos(const vector<IngredientType>& _ingredients);
	

};