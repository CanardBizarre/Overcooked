#include "RigidBodyComponent.h"

RigidBodyComponent::RigidBodyComponent(Actor* _owner) : Component(_owner)
{
	mass = 0.0f;
	high = 1.0f;
	gravity = ;
	roughness;
	elacticity;
	velocity;
}

RigidBodyComponent::RigidBodyComponent(Actor* _owner, const RigidBodyComponent& _other) : Component(_owner, _other)
{

}
