#include "KitchenBlock.h"

KitchenBlock::KitchenBlock(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle, 
	const BlockType& _type, const string& _name) : RigidProp(_level, RectangleShapeData(_size, "Blocks/spritesheet", PNG), _name)
{
	type = _type;
	mesh->SetOriginAtMiddle();
	SetPosition(_position);
	mesh->SetOriginAtMiddle();
	SetRotation(_angle);

	InitCollision();
}

KitchenBlock::KitchenBlock(const KitchenBlock& _other) : RigidProp(_other)
{
	type = _other.type;

	mesh->SetOriginAtMiddle();
	SetPosition(_other.GetPosition());
	SetRotation(_other.GetRotation());
	mesh->SetOriginAtMiddle();
}

void KitchenBlock::InitCollision()
{
	GetCollision()->SetInformation("KitchenBlock", IS_ALL, CT_BLOCK);
	vector<pair<string, CollisionType>> _reponses
	{
		{"Player", CT_BLOCK},
		{"Hand", CT_OVERLAP},
	};
	GetCollision()->AddResponses(_reponses);
	SetLayerType(PROP);
}

void KitchenBlock::CollisionEnter(const CollisionData& _data)
{
}

void KitchenBlock::CollisionUpdate(const CollisionData& _data)
{
}

void KitchenBlock::CollisionExit(const CollisionData& _data)
{
}

void KitchenBlock::Construct()
{
	Super::Construct();

}
