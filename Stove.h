#pragma once

#include "KitchenBlock.h"

class Stove : public KitchenBlock
{
public:
	Stove(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle = Angle());
	Stove(const Stove& _other);
};

