#include "RigidBodyComponent.h"
#include "Actor.h"
#include "DebugLevel.h"

RigidBodyComponent::RigidBodyComponent(Actor* _owner) : Component(_owner)
{
	mass = 20.0f;
	high = 1.0f;
	DebugLevel* _level = Cast<DebugLevel>(owner->GetLevel());
	gravity = _level->GetGravity();
	roughness = 0.5f;
	elasticity = 0.5f;
	velocity = Vector2f();
}


RigidBodyComponent::RigidBodyComponent(Actor* _owner, const RigidBodyComponent& _other) : Component(_owner, _other)
{
	mass = _other.mass;
	high = _other.high;
	DebugLevel* _level = Cast<DebugLevel>(owner->GetLevel());
	gravity = _level->GetGravity();
	roughness = _other.roughness;
	elasticity = _other.elasticity;
	velocity = Vector2f();
}

void RigidBodyComponent::ComputeVelocity()
{
	velocity *= elasticity;
	velocity.x *= roughness;
	velocity.y *= roughness;

	if (abs(velocity.x) < 1.0f)
	{
		velocity.x = 0.0f;
	}

	if (abs(velocity.y) < 1.0f)
	{
		velocity.y = 0.0f;
	}
	velocity *= mass;
}

void RigidBodyComponent::Tick(const float _deltaTime)
{
	ComputeVelocity();
}
