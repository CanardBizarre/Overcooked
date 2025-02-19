#pragma once
#include "VerticalBox.h"
#include "HorizontalBox.h"
#include "IngredientWidget.h"
#include "ProgressBarWidget.h"
using namespace UI;
class RecipeWidget : public VerticalBox
{	
	HorizontalBox* Ingredient;
	ProgressBarWidget* progressBar;
public:	
	RecipeWidget(Level* _level, HUD* _hud, vector<IngredientType> _ingredient, const float _time = 50.0f);
	RecipeWidget(const RecipeWidget& _other);
};