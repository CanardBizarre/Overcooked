#pragma once
#include "MeshActor.h"
#include "CollisionComponent.h"
#include "RigidBodyComponent.h"

class RigidActor : public MeshActor
{
	CollisionComponent* collision;
	RigidBodyComponent* rigidBody;

public:
	FORCEINLINE CollisionComponent* GetCollision() const
	{
		return collision;
	}
	FORCEINLINE RigidBodyComponent* GetRigidBody() const
	{
		return rigidBody;
	}


public:
	RigidActor(Level* _level, const RectangleShapeData& _data, const string& _name = "RigidActor");
	RigidActor(const RigidActor& _other);
};

