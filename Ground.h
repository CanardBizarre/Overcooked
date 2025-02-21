#pragma once
#include "Prop.h"

class Ground : public Prop
{
public:
	Ground(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle = Angle(),const string& _tetxure = "Blocks/ground");
	Ground(const Ground& _other);
};

