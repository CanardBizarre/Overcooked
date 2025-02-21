#include "DishWidget.h"
DishWidget::DishWidget(Level* _level, const DishType& _type, const float _size)
	:ImageWidget(_level, RectangleShapeData(Vector2f(_size, _size), "/Recipes/spritesheet", PNG))
{
	sizeF = _size;
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
