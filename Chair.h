#pragma once
#include "Prop.h"

class Chair : public Prop
{
public:
	Chair(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle = Angle());
	Chair(const Chair& _other);
};

