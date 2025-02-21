#pragma once
#include "Prop.h"

class Plant : public Prop
{
public:
	Plant(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle = Angle());
	Plant(const Plant& _other);
};

