#pragma once
#include "Component.h"

class RigidBodyComponent : public Component
{
	float mass;
	float high;
	float gravity;
	float roughness;
	float elacticity;
	Vector2f velocity;


public:
	virtual Component* Clone(Actor* _owner) const override
	{
		return new RigidBodyComponent(_owner, *this);
	}


public:

	RigidBodyComponent(Actor* _owner);
	RigidBodyComponent(Actor* _owner, const RigidBodyComponent& _other);
};

