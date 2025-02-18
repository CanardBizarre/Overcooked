#pragma once
#include "MeshActor.h"
#include "CollisionComponent.h"

class TestDummy :  public MeshActor
{
	CollisionComponent* collision;

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

