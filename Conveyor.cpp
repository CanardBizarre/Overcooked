#include "Conveyor.h"

Conveyor::Conveyor(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle)
	: KitchenBlock(_level, _size, _position, _angle, BT_CONVEYOR, "Conveyor")
{
	SetTextureRect(IntRect(Vector2i(124 * BT_CONVEYOR, 0), Vector2i(124 * 2, 124)));
}

Conveyor::Conveyor(const Conveyor& _other)
	: KitchenBlock(_other)
{
	SetTextureRect(IntRect(Vector2i(124 * BT_CONVEYOR, 0), Vector2i(124 * 2, 124)));
}
