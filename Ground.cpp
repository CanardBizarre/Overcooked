#include "Ground.h"

Ground::Ground(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle, const string& _tetxure)
	: Prop(_level, RectangleShapeData(_size, _tetxure), "Ground")
{
	mesh->SetOriginAtMiddle();
	SetPosition(_position);
	mesh->SetOriginAtMiddle();
	SetRotation(_angle);
}

Ground::Ground(const Ground& _other) : Prop(_other)
{

}
