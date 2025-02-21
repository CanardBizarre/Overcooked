#include "WorkPlan.h"
#include "TextureManager.h"
#include "Dish.h"

WorkPlan::WorkPlan(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle)
				: KitchenBlock(_level, _size, _position, _angle, BT_WORK_PLAN, "Work_Plan")
{
	SetTextureRect(IntRect(Vector2i(124 * BT_WORK_PLAN, 0), Vector2i(124, 124)));
}

WorkPlan::WorkPlan(const WorkPlan& _other) : KitchenBlock(_other)
{
	SetTextureRect(IntRect(Vector2i(124 * BT_WORK_PLAN, 0), Vector2i(124, 124)));
}

bool WorkPlan::EnterAction(Actor* _object, const bool _isDish)
{
	if (Ingredient* _ingredient = Cast<Ingredient>(_object))
	{
		set<Actor*> _children = GetChildren();
		for (Actor* _child : _children)
		{
			if (Dish* _dish = Cast<Dish>(_child))
			{
				_dish->AddIngredient(_ingredient);
				return true;
			}
		}
	}
	AddChild(_object, AT_KEEP_RELATIVE);
	_object->SetPosition(GetPosition());

	return true;
}

bool WorkPlan::ExitAction(Actor* _object)
{
	RemoveChild(_object);
	return true;
}
