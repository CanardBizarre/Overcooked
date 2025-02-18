#pragma once
#include "Component.h"

class RigidBodyComponent : public Component
{
	float mass;
	float high;
	float gravity;
	float roughness;
	float elasticity;
	Vector2f velocity;
	Vector2f fallMovement;

public:
	virtual Component* Clone(Actor* _owner) const override
	{
		return new RigidBodyComponent(_owner, *this);
	}


public:
	RigidBodyComponent(Actor* _owner, const float _mass = 0.0f ,const float _roughness = 0.0f, const float _elacticity = 0.0f);
	RigidBodyComponent(Actor* _owner, const RigidBodyComponent& _other);

public:
	Vector2f ComputeVelocity(const RigidBodyComponent& _other);
private:
	virtual void Tick(const float _deltaTime) override;
		

};

