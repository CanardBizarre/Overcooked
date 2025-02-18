#pragma once
#include "StaticKitchenBlock.h"

class StaticWorkPlan : public StaticKitchenBlock
{

public:
	StaticWorkPlan(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle = Angle());
	StaticWorkPlan(const StaticWorkPlan& _other);
};

