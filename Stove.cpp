#include "Stove.h"

Stove::Stove(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle)
	: KitchenBlock(_level, _size, _position, _angle, BT_STOVE, "Stove")
{
	SetTextureRect(IntRect(Vector2i(124 * BT_STOVE, 0), Vector2i(124, 124)));
}

Stove::Stove(const Stove& _other)
	: KitchenBlock(_other)
{
	SetTextureRect(IntRect(Vector2i(124 * BT_STOVE, 0), Vector2i(124, 124)));
}

bool Stove::EnterAction(Actor* _object, const bool _isDish)
{
	if (_isDish) return false;
	LOG(Display, "Enter");

	timer->Resume();
	AddChild(_object, AT_KEEP_RELATIVE);
	_object->SetPosition(GetPosition());

	// TODO AddChild lorsque dish et aliment sur le même workPlan

	return true;
}

bool Stove::ExitAction(Actor* _object)
{
	LOG(Display, "Exit");

	RemoveChild(_object);
	timer->Pause();
	return false;
}

void Stove::Construct()
{
	Super::Construct();

	timer = new Timer([&]() { FinishChopping(); }, seconds(3), false, true);
	timer->Reset();
}

void Stove::FinishChopping()
{
	timer->Pause();
	LOG(Warning, "Done Boiling");
}
