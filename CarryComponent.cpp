#include "CarryComponent.h"
#include "Actor.h"
#include "HandSocket.h"
#include "Level.h"
//TODO trouver un moyen pour les mettre dans le .h


Actor* CarryComponent::GetHand()
{
	return nullptr;
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
	handOffSet = 20.0f;
}

CarryComponent::CarryComponent(Actor* _owner, const CarryComponent& _other)
	:Component(_owner)
{
	handOffSet = _other.handOffSet;
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
		ThrowObject();
	}
	else if(_object)
	{
		PickUp(_object);
	}
}

void CarryComponent::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);

	const Vector2f& _foward = owner->GetForwardVector();
	const Vector2f& _position = owner->GetPosition();
	GetHand()->SetPosition(_position + handOffSet * _foward);
}


