#pragma once
#include "Prop.h"

class Table : public Prop
{
public:
	Table(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle = Angle());
	Table(const Table& _other);
};

