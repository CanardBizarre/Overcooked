#include "GarbageCan.h"

GarbageCan::GarbageCan(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle)
	: KitchenBlock(_level, _size, _position, _angle, BT_GARBAGE_CAN, "Garbage_Can")
{
	SetTextureRect(IntRect(Vector2i(124 * BT_GARBAGE_CAN, 0), Vector2i(124, 124)));
}

GarbageCan::GarbageCan(const GarbageCan& _other)
	: KitchenBlock(_other)
{
	SetTextureRect(IntRect(Vector2i(124 * BT_GARBAGE_CAN, 0), Vector2i(124, 124)));
}


bool GarbageCan::EnterAction(Actor* _object, const bool _isDish)
{
	//_object->SetToDelete();

	return true;
}
