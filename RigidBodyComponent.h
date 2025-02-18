#pragma once
#include "Component.h"

class RigidBodyComponent : public Component
{

public:
	virtual Component* Clone(Actor* _owner) const override
	{
		return new RigidBodyComponent(_owner, *this);
	}


public:

	RigidBodyComponent(Actor* _owner);
	RigidBodyComponent(Actor* _owner, const RigidBodyComponent& _other);
};

