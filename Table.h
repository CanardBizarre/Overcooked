#pragma once
#include "KitchenBlock.h"

class Table : public KitchenBlock
{
public:
	Table(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle = Angle());
	Table(const Table& _other);
};

