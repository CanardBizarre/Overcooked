#include "Wall.h"

Wall::Wall(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle)
	: Prop(_level, RectangleShapeData(_size, "/Blocks/wall"), "Wall")
{
	mesh->SetOriginAtMiddle();
	SetPosition(_position);
	mesh->SetOriginAtMiddle();
	SetRotation(_angle);
}

Wall::Wall(const Wall& _other) : Prop(_other)
{

}
