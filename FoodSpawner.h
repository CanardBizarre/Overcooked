#pragma once

#include "KitchenBlock.h"

class FoodSpawner : public KitchenBlock
{
public:
	FoodSpawner(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle = Angle());
	FoodSpawner(const FoodSpawner& _other);
};

