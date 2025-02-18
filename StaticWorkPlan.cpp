#include "StaticWorkPlan.h"
#include "TextureManager.h"

StaticWorkPlan::StaticWorkPlan(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle)
				: StaticKitchenBlock(_level, _size, _position, _angle, BT_WORK_PLAN, "Work_Plan")
{
	SetTextureRect(IntRect(Vector2i(124 * BT_WORK_PLAN,0), Vector2i(124,124)));
}

StaticWorkPlan::StaticWorkPlan(const StaticWorkPlan& _other) : StaticKitchenBlock(_other)
{
}
