#pragma once
#include "Component.h"
class MovementComponent : public Component
{
protected:
	Vector2f velocity;
	Vector2f direction;

public:


	FORCEINLINE Vector2f GetVelocity() const
	{
		return velocity;
	}
	FORCEINLINE void SetVelocity(const Vector2f& _velocity)
	{
		velocity = _velocity;
	}
	FORCEINLINE void SetDirection(Vector2f _direction)
	{
		direction = _direction;
	}
	FORCEINLINE Vector2f GetDiretion() const 
	{
		return direction;
	}
	FORCEINLINE bool IsDirectionNull() const
	{
		return direction == Vector2f();
	}
	FORCEINLINE virtual Component* Clone(Actor* _owner) const
	{
		return new MovementComponent(_owner, *this);
	}
public:
	MovementComponent(Actor* _owner, const Vector2f& _velocity = Vector2f(),
		const Vector2f& _direction = Vector2f());

	MovementComponent(Actor* _owner, const MovementComponent& _other);

	virtual ~MovementComponent();

protected:
	virtual void Move(const float _deltaTime);
public:
	virtual void Tick(const float _deltaTime);
};

