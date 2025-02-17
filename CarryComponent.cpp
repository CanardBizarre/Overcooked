#include "CarryComponent.h"
#include "Actor.h"
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
}

void CarryComponent::ThrowObject()
{
	RemoveObject();
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