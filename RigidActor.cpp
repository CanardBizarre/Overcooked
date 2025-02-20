#include "RigidActor.h"

RigidActor::RigidActor(Level* _level, const RectangleShapeData& _data, const string& _name) : MeshActor(_level, _data, _name)
{
	collision = CreateComponent<CollisionComponent>();
	rigidBody = CreateComponent<RigidBodyComponent>();
	movement = CreateComponent<MovementComponent>();
}

RigidActor::RigidActor(const RigidActor& _other) : MeshActor(_other)
{
	collision = CreateComponent<CollisionComponent>(*_other.collision);
	rigidBody = CreateComponent<RigidBodyComponent>(*_other.rigidBody);
	movement = CreateComponent<MovementComponent>(*_other.movement);
}

void RigidActor::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);
	movement->SetVelocity(rigidBody->GetVelocity());
	//LOG(Warning, to_string(rigidBody->GetVelocity().x) + " | " + to_string(rigidBody->GetVelocity().y));
	rigidBody->SetVelocity(movement->GetVelocity());
}
