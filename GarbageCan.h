#pragma once

#include "KitchenBlock.h"

class GarbageCan : public KitchenBlock
{
public:
	GarbageCan(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle = Angle());
	GarbageCan(const GarbageCan& _other);

public:
	bool EnterAction(Actor* _object, const bool _isDish);
};

