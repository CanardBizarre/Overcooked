#include "ChoppingStation.h"
#include "Ingredient.h"

ChoppingStation::ChoppingStation(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle)
	: KitchenBlock(_level, _size, _position, _angle, BT_CHOPPING_STATION, "Chopping_Station")
{
	SetTextureRect(IntRect(Vector2i(124 * BT_CHOPPING_STATION, 0), Vector2i(124, 124)));
}

ChoppingStation::ChoppingStation(const ChoppingStation& _other)
	: KitchenBlock(_other)
{
	SetTextureRect(IntRect(Vector2i(124 * BT_CHOPPING_STATION, 0), Vector2i(124, 124)));
}

bool ChoppingStation::EnterAction(Actor* _object, const bool _isDish)
{
	if (_isDish) return false;

	if (Ingredient* _ingredient = Cast<Ingredient>(_object))
	{
		if (_ingredient->IsSliced()) return false;

		_ingredient->GetChoppingTimer()->Resume();
	}
	AddChild(_object, AT_KEEP_RELATIVE);
	_object->SetPosition(GetPosition());

	return true;
}

bool ChoppingStation::ExitAction(Actor* _object)
{

	RemoveChild(_object);
	if (Ingredient* _ingredient = Cast<Ingredient>(_object))
	{
		_ingredient->GetChoppingTimer()->Pause();
	}
	return false;
}

void ChoppingStation::Construct()
{
	Super::Construct();
}