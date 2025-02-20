#include "Wall.h"

Wall::Wall(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle)
	: KitchenBlock(_level, _size, _position, _angle, BT_WALL, "Work_Plan", "/Blocks/wall")
{
}

Wall::Wall(const Wall& _other) : KitchenBlock(_other)
{
}
