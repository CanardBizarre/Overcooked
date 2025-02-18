#include "CarryComponent.h"
#include "Actor.h"
//TODO trouver un moyen pour les mettre dans le .h

Actor* CarryComponent::GetHand()
{
	if (owner->GetChildren().size() == 0)
	{
		owner->CreateSocket("Hand", TransformData(), AT_KEEP_RELATIVE);
	}
	return owner->GetChildrenAtIndex(0);
}

bool CarryComponent::IsCarryingAnObject()
{
	Actor* _socket = owner->GetChildrenAtIndex(0);
	return _socket->GetChildren().size() == 1;
}

Actor* CarryComponent::GetCarriedObject()
{
	if (!IsCarryingAnObject()) return nullptr;
	return  owner->GetChildrenAtIndex(0)->GetChildrenAtIndex(0);
}

void CarryComponent::RemoveObject()
{
	Actor* _current = GetCarriedObject();
	owner->GetChildrenAtIndex(0)->RemoveChild(_current);
}

//////////////////////////////////////////////////


CarryComponent::CarryComponent(Actor* _owner)
	:Component(_owner)
{

}

CarryComponent::CarryComponent(Actor* _owner, const CarryComponent& _other)
	:Component(_owner)
{

}


void CarryComponent::PickUp(Actor* _object)
{
	Actor* _socket = owner->GetChildrenAtIndex(0);
	_socket->AddChild(_object, AT_KEEP_RELATIVE);
}

void CarryComponent::DropObject()
{
	RemoveObject();
	// TODO Lacher l'objet
}

void CarryComponent::ThrowObject()
{
	RemoveObject();
	// TODO Jeter l'objet
}

void CarryComponent::Action(Actor* _object)
{
	if (IsCarryingAnObject())
	{
		DropObject();
	}
	else if(_object)
	{
		PickUp(_object);
	}
}


