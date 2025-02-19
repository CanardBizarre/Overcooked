#include "Sink.h"

Sink::Sink(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle)
	: KitchenBlock(_level, _size, _position, _angle, BT_SINK, "Sink")
{
	SetTextureRect(IntRect(Vector2i(124 * BT_SINK + 124, 0), Vector2i(124 * 2, 124)));
}

Sink::Sink(const Sink& _other)
	: KitchenBlock(_other)
{
	SetTextureRect(IntRect(Vector2i(124 * BT_SINK, 0), Vector2i(124 * 2, 124)));
}
