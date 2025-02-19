#pragma once
#include "KitchenBlock.h"

class Wall : public KitchenBlock
{
public:
	Wall(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle = Angle());
	Wall(const Wall& _other);
};

