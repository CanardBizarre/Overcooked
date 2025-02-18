#pragma once
#include "RigidActor.h"

class RigidProp : public RigidActor
{

public:
	RigidProp(Level* _level, const RectangleShapeData& _data, const string& _name = "RigidProp");
	RigidProp(const RigidProp& _other);

public:
	virtual void CollisionEnter(const CollisionData& _data) override;
	virtual void CollisionUpdate(const CollisionData& _data) override;
	virtual void CollisionExit(const CollisionData& _data) override;
};

