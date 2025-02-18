#pragma once
#include "KitchenBlock.h"

class StaticKitchenBlock : public KitchenBlock
{

public:
	StaticKitchenBlock(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle
		              , const BlockType& _type, const string& _name = "StaticKitchenBlock");

	StaticKitchenBlock(const StaticKitchenBlock& _other);
};

