#pragma once
#include "MeshActor.h"
#include "CollisionComponent.h"
#include "RigidBodyComponent.h"
#include "MovementComponent.h"

class RigidActor : public MeshActor
{
protected:
	CollisionComponent* collision;
	RigidBodyComponent* rigidBody;
	MovementComponent* movement;

public:
	FORCEINLINE CollisionComponent* GetCollision() const
	{
		return collision;
	}
	FORCEINLINE RigidBodyComponent* GetRigidBody() const
	{
		return rigidBody;
	}
	FORCEINLINE MovementComponent* GetMovement() const
	{
		return movement;
	}


public:
	RigidActor(Level* _level, const RectangleShapeData& _data, const string& _name = "RigidActor");
	RigidActor(const RigidActor& _other);

	virtual void Tick(const float _deltaTime) override
	{

	}
};

