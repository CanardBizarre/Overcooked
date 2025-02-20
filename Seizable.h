#pragma once
#include "RigidProp.h"

enum SeizableType
{
	ST_DISH,
	ST_INGREDIENT,
	ST_CONTAINER,
	ST_COUNT,
};

class Seizable : public RigidProp
{
public: 
	Seizable() = default;
	Seizable(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle,
		const SeizableType& _type, const string& _path, const string& _name = "Seizable");
	Seizable(const Seizable& _other);

public:
	void InitCollision();
	void Throw(const Vector2f& _direction);
};

