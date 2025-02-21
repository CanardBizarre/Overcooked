#pragma once

#include "Seizable.h"

class Dish : public Seizable
{
public:
	Dish(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle, const string& _name = "Dish");


};

