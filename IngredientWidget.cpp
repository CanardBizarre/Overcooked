#include "IngredientWidget.h"
IngredientWidget::IngredientWidget(Level* _level, const IngredientType& _type)
	:ImageWidget(_level, RectangleShapeData(Vector2f(25.0f, 25.0f), "/Ingredients/spritesheet", PNG))
{
	type = _type;
	state = IS_RAW;
	SetRect(IntRect(Vector2i(124 * type, 124 * state), Vector2i(124, 124)));
}

IngredientWidget::IngredientWidget(const IngredientWidget& _other)
	:ImageWidget(_other)
{
	type = _other.type;
	state = _other.state;
}