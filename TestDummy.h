#pragma once
#include "RigidActor.h"
#include "CollisionComponent.h"

class TestDummy :  public RigidActor
{

public:
	TestDummy(Level* _level);
	TestDummy(const TestDummy& _other);

private:
	void InitCollision();

public:
	virtual void CollisionEnter(const CollisionData& _data) override;
	virtual void CollisionUpdate(const CollisionData& _data)  override;
	virtual void CollisionExit(const CollisionData& _data)  override;

};

