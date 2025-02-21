#include "Table.h"

Table::Table(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle)
	: Prop(_level, RectangleShapeData(_size, "/Blocks/Table"), "Table")
{
	mesh->SetOriginAtMiddle();
	SetPosition(_position);
	mesh->SetOriginAtMiddle();
	SetRotation(_angle);
}

Table::Table(const Table& _other) : Prop(_other)
{
	
}
