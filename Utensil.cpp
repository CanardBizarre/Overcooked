#include "Utensil.h"

Utensil::Utensil(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle,
	const UtensilType& _type, const string& _name)
	: Seizable(_level, _size, _position, _angle, ST_UTENSIL, "Props/spritesheet", _name)
{
	SetTextureRect(IntRect(Vector2i(124 * _type, 0), Vector2i(124, 124)));
}

