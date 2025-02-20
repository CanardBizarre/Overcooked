#pragma once
#include "VerticalBox.h"
#include "HorizontalBox.h"
#include "IngredientWidget.h"
#include "ProgressBarWidget.h"
#include "Chronometer.h"
#include "DishWidget.h"

using namespace UI;
class OrderWidget : public CanvasWidget
{	
	Chronometer* chrono;
	vector<IngredientWidget*> ingredient;
	ProgressBarWidget* progressBar;


public:
	FORCEINLINE bool IsCanceled() const
	{
		return chrono->IsEnd();
	}

public:	
	OrderWidget(Level* _level, HUD* _hud, const DishType& _dishType, vector<IngredientType> _ingredient, const string& _name = "Orders", const float _time = 50.0f);
	OrderWidget(const OrderWidget& _other);
	~OrderWidget();

public:
	virtual void Tick(const float _deltaTime) override;

};