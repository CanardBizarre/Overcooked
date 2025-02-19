#pragma once
#include "ImageWidget.h"
#include "IngredientType.h"
using namespace UI;

class IngredientWidgetB : public ImageWidget
{
	IngredientType type;

public:
	IngredientWidgetB(Level* _level, const IngredientType& _type);
	IngredientWidgetB(const IngredientWidgetB& _other);
};

