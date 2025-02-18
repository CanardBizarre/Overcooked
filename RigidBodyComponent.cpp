#include "RigidBodyComponent.h"
#include "Actor.h"
#include "DebugLevel.h"

RigidBodyComponent::RigidBodyComponent(Actor* _owner, const float _mass, const float _roughness, const float _elacticity) : Component(_owner)
{
	mass = _mass;
	high = 1.0f;
	DebugLevel* _level = Cast<DebugLevel>(owner->GetLevel());
	gravity = _level->GetGravity();
	roughness = _roughness;
	elasticity = _elacticity;
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

Vector2f RigidBodyComponent::ComputeVelocity(const RigidBodyComponent& _other)
{
	velocity *= (elasticity + _other.elasticity) / 2;
	velocity.x *= roughness + _other.roughness;
	velocity.y *= roughness + _other.roughness;

	if (abs(velocity.x) < 1.0f)
	{
		velocity.x = 0.0f;
	}

	if (abs(velocity.y) < 1.0f)
	{
		velocity.y = 0.0f;
	}
	return velocity;
}

void RigidBodyComponent::Tick(const float _deltaTime)
{

}
