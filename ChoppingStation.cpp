#include "ChoppingStation.h"

ChoppingStation::ChoppingStation(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle)
	: KitchenBlock(_level, _size, _position, _angle, BT_CHOPPING_STATION, "Chopping_Station")
{
	SetTextureRect(IntRect(Vector2i(124 * BT_CHOPPING_STATION, 0), Vector2i(124, 124)));
}

ChoppingStation::ChoppingStation(const ChoppingStation& _other)
	: KitchenBlock(_other)
{
	SetTextureRect(IntRect(Vector2i(124 * BT_CHOPPING_STATION, 0), Vector2i(124, 124)));
}
