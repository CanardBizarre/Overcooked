#pragma once
#include "KitchenBlock.h"

class Ground : public KitchenBlock
{
public:
	Ground(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle = Angle(),const string& _tetxure = "Blocks/ground");
	Ground(const Ground& _other);
};

