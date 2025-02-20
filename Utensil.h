#pragma once

#include "Seizable.h"

enum UtensilType
{
	UT_FIRE_EXTINGUISHER = 1,
	UT_PAN,
	UT_POT,
	UT_COUNT,
};

class Utensil : public Seizable
{
	UtensilType type;
public:
	Utensil(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle, 
		const UtensilType& _type, const string& _name = "Utensil");

};

