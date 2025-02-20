#include "IngredientWidget.h"
IngredientWidget::IngredientWidget(Level* _level, const IngredientType& _type)
	:ImageWidget(_level, RectangleShapeData(Vector2f(15.0f, 15.0f), "/Ingredients/spritesheet", PNG))
{
	type = _type;
	state = IS_RAW;
	SetRect(IntRect(Vector2i(124 * type, 124 * state), Vector2i(124, 124)));
	isCookable = false;
	InitState();
}

IngredientWidget::IngredientWidget(const IngredientWidget& _other)
	:ImageWidget(_other)
{
	type = _other.type;
	state = _other.state;
}

void IngredientWidget::InitState()
{
	if (type == IT_TORTILLA
		|| type == IT_CHICKEN
		|| type == IT_MEAT
		|| type == IT_RICE
		|| type == IT_MUSHROOM)
	{isCookable = true;}
}

