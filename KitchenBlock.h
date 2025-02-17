#pragma once
#include "RigidProp.h"


enum BlockType
{
	BT_WORK_PLAN,
	BT_CONVEYOR,
	BT_GARBAGE_CAN,
	BT_SINK,
	BT_EXTINGUISHER,
	BT_PLANK,
	BT_HEATING_PLATE,
	BT_FOOD_SPAWNER,
	BT_PLATE_SPAWNER,
	BT_PLATES,
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
	KitchenBlock(Level* _level, const Vector2f& _position, const Angle& _angle, const BlockType& _type, const RectangleShapeData& _data, const string& _name = "KitchenBlock");
	KitchenBlock(const KitchenBlock& _other);
};

