#pragma once
#include "KitchenBlock.h"

class Plant : public KitchenBlock
{
public:
	Plant(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle = Angle());
	Plant(const Plant& _other);
};

