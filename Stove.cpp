#include "Stove.h"

Stove::Stove(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle)
	: KitchenBlock(_level, _size, _position, _angle, BT_STOVE, "Stove")
{
	SetTextureRect(IntRect(Vector2i(124 * BT_STOVE, 0), Vector2i(124, 124)));
}

Stove::Stove(const Stove& _other)
	: KitchenBlock(_other)
{
	SetTextureRect(IntRect(Vector2i(124 * BT_STOVE, 0), Vector2i(124, 124)));
}
