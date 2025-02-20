#include "IngredientWidget.h"
IngredientWidget::IngredientWidget(Level* _level, const IngredientType& _type)
	:ImageWidget(_level, RectangleShapeData(Vector2f(25.0f, 25.0f), "/Ingredients/spritesheet", PNG))
{
	SetRect(IntRect(Vector2i(124 * _type, 0), Vector2i(124, 124)));
	type = _type;
}

IngredientWidget::IngredientWidget(const IngredientWidget& _other)
	:ImageWidget(_other)
{
	type = _other.type;
}

void IngredientWidget::Reuse(const IngredientType& _type)
{
	SetRect(IntRect(Vector2i(124 * _type, 0), Vector2i(124, 124)));
	type = _type;
}

