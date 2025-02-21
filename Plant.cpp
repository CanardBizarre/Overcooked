#include "Plant.h"

Plant::Plant(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle)
	: Prop(_level, RectangleShapeData(_size, "/Blocks/Plant"), "Plant")
{
	mesh->SetOriginAtMiddle();
	SetPosition(_position);
	mesh->SetOriginAtMiddle();
	SetRotation(_angle);
}

Plant::Plant(const Plant& _other) : Prop(_other)
{
}
