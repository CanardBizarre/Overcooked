#pragma once
#include "Component.h"

class Actor;
struct TransformData;
class CarryComponent :  public Component
{
	virtual Component* Clone(Actor* _owner) const
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
	Actor* GetHand();
	bool IsCarryingAnObject();
	Actor* GetCarriedObject();
	void RemoveObject();

public:
	void Action(Actor* _object);
};

