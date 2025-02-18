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

	FORCEINLINE Vector2f GetVelocity() const
	{
		return velocity;
	}

	FORCEINLINE void SetVelocity(const Vector2f& _velocity )
	{
		velocity = _velocity;
	}

public:
	RigidBodyComponent(Actor* _owner);
	RigidBodyComponent(Actor* _owner, const RigidBodyComponent& _other);

public:
	virtual void Tick(const float _deltaTime) override;
private:
	void ComputeVelocity(const float _deltaTime);

};

