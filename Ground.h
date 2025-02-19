#pragma once
#include "KitchenBlock.h"

class Ground : public KitchenBlock
{
public:
	Ground(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle = Angle());
	Ground(const Ground& _other);
};

