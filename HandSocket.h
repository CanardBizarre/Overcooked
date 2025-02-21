#pragma once
#include "Actor.h"
#include "CollisionComponent.h"
#include "MeshComponent.h"
#include "KitchenBlock.h"

class HandSocket : public Actor
{
	float handOffSet;
	bool isNearCounter;
	bool isDish;
	MeshComponent* mesh;
	CollisionComponent* collision;
	Actor* object;
	KitchenBlock* nearestBlock;

public:
	FORCEINLINE virtual void SetPosition(const Vector2f& _position) override
	{
		Super::SetPosition(_position);
		mesh->GetShape()->SetPosition(_position);
	}
	FORCEINLINE virtual void SetRotation(const Angle& _rotation) override
	{
		Super::SetRotation(_rotation);
		mesh->GetShape()->SetRotation(_rotation);
	}
	FORCEINLINE virtual void SetScale(const Vector2f& _scale) override
	{
		Super::SetScale(_scale);
		mesh->GetShape()->SetScale(_scale);
	}
	FORCEINLINE virtual void SetOrigin(const Vector2f& _origin) override
	{
		Super::SetOrigin(_origin);
		mesh->GetShape()->SetOrigin(_origin);
	}
	FORCEINLINE virtual void Move(const Vector2f& _offset) override
	{
		Super::Move(_offset);
		mesh->GetShape()->Move(_offset);
	}
	FORCEINLINE virtual void Rotate(const Angle& _angle) override
	{
		Super::Rotate(_angle);
		mesh->GetShape()->Rotate(_angle);
	}
	FORCEINLINE virtual void Scale(const Vector2f& _factor) override
	{
		Super::Scale(_factor);
		mesh->GetShape()->Scale(_factor);
	}
	FORCEINLINE bool IsCarryingAnObject()
	{
		return GetChildren().size() == 1;
	}
	FORCEINLINE Actor* GetCarriedObject()
	{
		if (!IsCarryingAnObject()) return nullptr;
		return GetChildrenAtIndex(0);
	}
	FORCEINLINE Actor* RemoveObject()
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

public:
	void ThrowObject();
	void InitCollision();
	void HandAction();

	virtual void CollisionEnter(const CollisionData& _data) override;
	virtual void CollisionUpdate(const CollisionData& _data)  override;
	virtual void CollisionExit(const CollisionData& _data)  override;

	void Tick(const float _deltaTime);
	virtual void Construct() override;

	virtual void SetZOrder(const int _zOrder) override;
	
};