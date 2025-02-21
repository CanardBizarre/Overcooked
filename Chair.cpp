#include "Chair.h"

Chair::Chair(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle)
	: Prop(_level, RectangleShapeData(_size, "/Blocks/Chair"), "Chair")
{
	mesh->SetOriginAtMiddle();
	SetPosition(_position);
	mesh->SetOriginAtMiddle();
	SetRotation(_angle);
}

Chair::Chair(const Chair& _other) : Prop(_other)
{
	
}
