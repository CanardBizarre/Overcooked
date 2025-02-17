#include "KitchenBlock.h"

KitchenBlock::KitchenBlock(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle, const BlockType& _type, const string& _name) : RigidProp(_level, RectangleShapeData(_size, "/Blocks/blocks_spritesheet", PNG), _name)
{
	type = _type;
	SetPosition(_position);
	SetRotation(_angle);
}

KitchenBlock::KitchenBlock(const KitchenBlock& _other) : RigidProp(_other)
{
	type = _other.type;
	SetPosition(_other.GetPosition());
	SetRotation(_other.GetRotation());
}
