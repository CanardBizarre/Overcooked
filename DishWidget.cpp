#include "DishWidget.h"
DishWidget::DishWidget(Level* _level, const DishType& _type)
	:ImageWidget(_level, RectangleShapeData(Vector2f(40.0f, 40.0f), "/Dish/spritesheet", PNG))
{
	SetRect(IntRect(Vector2i(124 * _type, 0), Vector2i(124, 124)));
	type = _type;
	SetOriginAtMiddle();
}

DishWidget::DishWidget(const DishWidget& _other)
	:ImageWidget(_other)
{
	type = _other.type;
}

void DishWidget::Reuse(const DishType& _type)
{
	SetRect(IntRect(Vector2i(124 * _type, 0), Vector2i(124, 124)));
}
