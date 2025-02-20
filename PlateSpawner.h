#pragma once

#include "KitchenBlock.h"

class PlateSpawner : public KitchenBlock
{
public:
	PlateSpawner(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle = Angle());
	PlateSpawner(const PlateSpawner& _other);
};

