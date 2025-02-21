#pragma once
#include "Prop.h"

class Wall : public Prop
{
public:
	Wall(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle = Angle());
	Wall(const Wall& _other);
};

