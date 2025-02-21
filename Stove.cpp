#include "Stove.h"
#include "Ingredient.h"

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

	if (Ingredient* _ingredient = Cast<Ingredient>(_object))
	{
		if (!_ingredient->IsSliced()) return false;

		_ingredient->GetBoilingTimer()->Resume();
	}

	AddChild(_object, AT_KEEP_RELATIVE);
	_object->SetPosition(GetPosition());

	LOG(Display, "Enter");
	return true;
}

bool Stove::ExitAction(Actor* _object)
{
	LOG(Display, "Exit");

	RemoveChild(_object);
	if (Ingredient* _ingredient = Cast<Ingredient>(_object))
	{
		_ingredient->GetBoilingTimer()->Pause();
	}
	return false;
}

void Stove::Construct()
{
	Super::Construct();


}
