#pragma once
#include "MeshActor.h"
#include "CollisionComponent.h"
#include "MovementComponent.h"

class TestDummy :  public MeshActor
{
	CollisionComponent* collision;
	MovementComponent* move; 
public:
	TestDummy(Level* _level);
	TestDummy(const TestDummy& _other);

private:
	void InitCollision();

public:
	void Throw(const Vector2f& _direction);
	virtual void CollisionEnter(const CollisionData& _data) override;
	virtual void CollisionUpdate(const CollisionData& _data)  override;
	virtual void CollisionExit(const CollisionData& _data)  override;

};

