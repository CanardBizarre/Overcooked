#pragma once
#include "RigidProp.h"


enum BlockType
{
	BT_WORK_PLAN,
	BT_GARBAGE_CAN,
	BT_CHOPPING_STATION,
	BT_STOVE,
	BT_FOOD_SPAWNER,
	BT_PLATE_SPAWNER,
	BT_CONVEYOR,
	BT_SINK,
	BT_COUNT
};





class KitchenBlock : public RigidProp
{
	BlockType type;

public:
	FORCEINLINE BlockType GetType() const
	{
		return type;
	}

public:
	KitchenBlock(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle, const BlockType& _type, const string& _name = "KitchenBlock");
	KitchenBlock(const KitchenBlock& _other);

public:
	void InitCollision();

	virtual void CollisionEnter(const CollisionData& _data) override;
	virtual void CollisionUpdate(const CollisionData& _data) override;
	virtual void CollisionExit(const CollisionData& _data) override;

	virtual void Construct() override;
};

