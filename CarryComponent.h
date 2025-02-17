#pragma once
#include "Component.h"
class CarryComponent :  public Component
{

public:
	FORCEINLINE bool IsCarryingAnObject()
	{
		Actor* _socket = owner->GetChildrenAtIndex(0);
		return _socket->GetChildren().size() == 1;
	}
	FORCEINLINE Actor* GetCarriedObject()
	{
		if (!IsCarryingAnObject()) return;
		return  owner->GetChildrenAtIndex(0)->GetChildrenAtIndex(0);
	}
	FORCEINLINE void RemoveObject()
	{
		Actor* _current = GetCarriedObject();
		owner->GetChildrenAtIndex(0)->RemoveChild(_current);
	}
	FORCEINLINE virtual Component* Clone(Actor* _owner) const
	{
		return new CarryComponent(_owner, *this);
	}
public:
	CarryComponent(Actor* _owner);
	CarryComponent(Actor* _owner, const CarryComponent& _other);

private:
	void PickUp(Actor* _object);
	void DropObject();
	void ThrowObject();

public:
	void Action(Actor* _object);
};

