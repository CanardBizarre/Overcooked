#pragma once
#include "KitchenBlock.h"

class Chair : public KitchenBlock
{
public:
	Chair(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle = Angle());
	Chair(const Chair& _other);
};

