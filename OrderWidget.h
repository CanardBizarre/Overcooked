#pragma once
#include "VerticalBox.h"
#include "HorizontalBox.h"
#include "IngredientWidget.h"
#include "ProgressBarWidget.h"
#include "Chronometer.h"
using namespace UI;
class OrderWidget : public VerticalBox
{	
	Chronometer* chrono;
	HorizontalBox* Ingredient;
	ProgressBarWidget* progressBar;
public:	
	OrderWidget(Level* _level, HUD* _hud, vector<IngredientType> _ingredient, const float _time = 50.0f);
	OrderWidget(const OrderWidget& _other);
	~OrderWidget();

public:
	virtual void Tick(const float _deltaTime) override;

};