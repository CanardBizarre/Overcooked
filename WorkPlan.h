#pragma once
#include "KitchenBlock.h"

class WorkPlan : public KitchenBlock
{

public:
	WorkPlan(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle = Angle());
	WorkPlan(const WorkPlan& _other);
};

