#include "Chair.h"

Chair::Chair(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle)
	: KitchenBlock(_level, _size, _position, _angle, BT_CHAIR, "Work_Plan", "/Blocks/Chair")
{
}

Chair::Chair(const Chair& _other) : KitchenBlock(_other)
{
}
