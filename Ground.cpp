#include "Ground.h"

Ground::Ground(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle, const string& _tetxure)
	: KitchenBlock(_level, _size, _position, _angle, BT_BLUE_GROUND, "Work_Plan", _tetxure)
{
}

Ground::Ground(const Ground& _other) : KitchenBlock(_other)
{
}
