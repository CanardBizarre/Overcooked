#include "RigidActor.h"

RigidActor::RigidActor(Level* _level, const RectangleShapeData& _data, const string& _name) : MeshActor(_level, _data, _name)
{
	collision = CreateComponent<CollisionComponent>();
	rigidBody = CreateComponent<RigidBodyComponent>();
}

RigidActor::RigidActor(const RigidActor& _other) : MeshActor(_other)
{
	collision = CreateComponent<CollisionComponent>(*_other.collision);
	rigidBody = CreateComponent<RigidBodyComponent>(*_other.rigidBody);
}
