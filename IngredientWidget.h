#pragma once
#include "ImageWidget.h"
#include "IngredientType.h"

using namespace UI;
class IngredientWidget : public ImageWidget
{
	IngredientType type;

public:
	IngredientWidget(Level* _level, const IngredientType& _type);
	IngredientWidget(const IngredientWidget& _other);

public:
	void Reuse(const IngredientType& _type);
};

