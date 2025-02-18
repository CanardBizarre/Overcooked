#pragma once

#include "KitchenBlock.h"

class ChoppingStation : public KitchenBlock
{
public:
	ChoppingStation(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle = Angle());
	ChoppingStation(const ChoppingStation& _other);
};

