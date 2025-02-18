#include "RigidBodyComponent.h"

RigidBodyComponent::RigidBodyComponent(Actor* _owner) : Component(_owner)
{
}

RigidBodyComponent::RigidBodyComponent(Actor* _owner, const RigidBodyComponent& _other) : Component(_owner, _other)
{
}
