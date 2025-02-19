#include "PlateSpawner.h"

PlateSpawner::PlateSpawner(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle)
	: KitchenBlock(_level, _size, _position, _angle, BT_PLATE_SPAWNER, "Plate_Spawner")
{
	SetTextureRect(IntRect(Vector2i(124 * BT_PLATE_SPAWNER, 0), Vector2i(124, 124)));
}

PlateSpawner::PlateSpawner(const PlateSpawner& _other)
	: KitchenBlock(_other)
{
	SetTextureRect(IntRect(Vector2i(124 * BT_PLATE_SPAWNER, 0), Vector2i(124, 124)));
}

