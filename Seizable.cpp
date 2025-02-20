#include "Seizable.h"

Seizable::Seizable(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle,
	const SeizableType& _type, const string& _path, const string& _name)
	: RigidProp(_level, RectangleShapeData(_size, _path, PNG, false), _name)
{
	mesh->SetOriginAtMiddle();
	InitCollision();
}

Seizable::Seizable(const Seizable& _other)
	:RigidProp(_other)
{
	mesh->SetOriginAtMiddle();
}

void Seizable::InitCollision()
{
	GetCollision()->SetInformation("Seizable", IS_ALL, CT_OVERLAP);
	vector<pair<string, CollisionType>> _reponses
	{
		{"Hand", CT_OVERLAP},
	};
	GetCollision()->AddResponses(_reponses);
	SetLayerType(PROP);
}

void Seizable::Throw(const Vector2f& _direction)
{
	movement->SetDirection(_direction);
}