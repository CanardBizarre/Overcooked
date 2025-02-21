#include "IngredientWidget.h"
IngredientWidget::IngredientWidget(Level* _level, const IngredientType& _type, const float _size)
	:ImageWidget(_level, RectangleShapeData(Vector2f(_size, _size), "/Ingredients/spritesheet", PNG))
{
	sizeF = _size;
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

void IngredientWidget::Reuse(const IngredientType& _type)
{
	SetRect(IntRect(Vector2i(124 * _type, 0), Vector2i(124, 124)));
	type = _type;
}

