#include "IngredientWidgetB.h"

IngredientWidgetB::IngredientWidgetB(Level* _level, const IngredientType& _type)
	:ImageWidget(_level, RectangleShapeData(Vector2f(25.0f, 25.0f), "/Ingredients/spritesheet", PNG))
{
	SetRect(IntRect(Vector2i(124 * _type, 0), Vector2i(124, 124)));
}

IngredientWidgetB::IngredientWidgetB(const IngredientWidgetB& _other)
	:ImageWidget(_other)
{

}
