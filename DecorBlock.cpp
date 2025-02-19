#include "DecorBlock.h"

DecorBlock::DecorBlock(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle, const DecorBlockType& _type, const string& _texture, const string& _name)
	: RigidProp(_level, RectangleShapeData(_size, _texture, PNG), _name)
{
	type = _type;

	SetPosition(_position);
	SetRotation(_angle);

	InitCollision();
}

DecorBlock::DecorBlock(const DecorBlock& _other) : RigidProp(_other)
{
	type = _other.type;
	SetPosition(_other.GetPosition());
	SetRotation(_other.GetRotation());
}

void DecorBlock::InitCollision()
{
	GetCollision()->SetInformation("DecorBlock", IS_ALL, CT_BLOCK);
	vector<pair<string, CollisionType>> _reponses
	{
		{"Player", CT_BLOCK},
		{"Hand", CT_OVERLAP},
	};
	GetCollision()->AddResponses(_reponses);
	SetLayerType(PROP);
}

void DecorBlock::CollisionEnter(const CollisionData& _data)
{
}

void DecorBlock::CollisionUpdate(const CollisionData& _data)
{
}

void DecorBlock::CollisionExit(const CollisionData& _data)
{
}

void DecorBlock::Construct()
{
	Super::Construct();
}
