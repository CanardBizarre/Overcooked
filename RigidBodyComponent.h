#pragma once
#include "Component.h"

class RigidBodyComponent : public Component
{
	float mass;
	float high;
	bool isFall;
	float gravity;
	float roughness;
	float elasticity;
	Vector2f velocity;
	Vector2f ownerScale;

public:
	virtual Component* Clone(Actor* _owner) const override
	{
		return new RigidBodyComponent(_owner, *this);
	}

	FORCEINLINE Vector2f GetVelocity() const
	{
		return velocity;
	}

	FORCEINLINE void SetVelocity(const Vector2f& _velocity )
	{
		velocity = _velocity;
	}
	FORCEINLINE float GetHigh() const
	{
		return high;
	}
	FORCEINLINE void SetHigh(const float _high)
	{
		high = _high;
	}
	FORCEINLINE void SetIsFall(const bool _fall)
	{
		isFall = _fall;
	}

public:
	RigidBodyComponent(Actor* _owner);
	RigidBodyComponent(Actor* _owner, const RigidBodyComponent& _other);

public:
	virtual void Tick(const float _deltaTime) override;
	void ApplyBounce(const vector<Vector2f>& _edge, const Vector2f& _otherVelocity);
private:
	Vector2f ComputeEdgeNormal(const vector<Vector2f>& _edge);
	void ComputeVelocity(const float _deltaTime);

	void DiscreaseHigh(const float _deltaTime);

	void Rescale();

};

