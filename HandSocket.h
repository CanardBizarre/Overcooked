#pragma once
#include "Actor.h"
#include "CollisionComponent.h"
#include "MeshComponent.h"

class HandSocket :  public Actor
{
	float handOffSet; 
	float isNearCounter; 
	CollisionComponent* collision;
	Actor* object;

public:
	bool IsCarryingAnObject()
	{
		return GetChildren().size() == 1;
	}

	Actor* GetCarriedObject()
	{
		if (!IsCarryingAnObject()) return nullptr;
		return GetChildrenAtIndex(0);
	}
	Actor* RemoveObject()
	{
		Actor* _current = GetCarriedObject();
		RemoveChild(_current);
		return _current;
	}


public:
	HandSocket(Level* _level, const Vector2f& _pos, const float _handOffSet);
	HandSocket(Level* _level, HandSocket* _other);

private:
	void PickUp();
	void DropObject();
	void ThrowObject();

public:
	void InitCollision();
	void Action();

	virtual void CollisionEnter(const CollisionData& _data) override;
	virtual void CollisionUpdate(const CollisionData& _data)  override;
	virtual void CollisionExit(const CollisionData& _data)  override;

	void Tick(const float _deltaTime);
};

