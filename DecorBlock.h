#pragma once
#include "RigidProp.h"


enum DecorBlockType
{
	DB_WALL = 9,
	DB_TABLE,
	DB_CHAIR,
	DB_PLANT,
	DB_COUNT
};

class DecorBlock : public RigidProp
{
	DecorBlockType type;

public:
	FORCEINLINE DecorBlockType GetType() const
	{
		return type;
	}

public:
	DecorBlock(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle, const DecorBlockType& _type, const string& _texture, const string& _name = "KitchenBlock");
	DecorBlock(const DecorBlock& _other);

public:
	void InitCollision();

	virtual void CollisionEnter(const CollisionData& _data) override;
	virtual void CollisionUpdate(const CollisionData& _data) override;
	virtual void CollisionExit(const CollisionData& _data) override;

	virtual void Construct() override;
};

