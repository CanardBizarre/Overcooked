#pragma once

#include "KitchenBlock.h"

class Conveyor : public KitchenBlock
{
public:
	Conveyor(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle = Angle());
	Conveyor(const Conveyor& _other);
};

