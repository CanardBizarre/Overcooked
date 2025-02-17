#pragma once
#include "Component.h"
class MovementComponent : public Component
{
protected:
	float speed; 
	Vector2f direction;

public:


	FORCEINLINE float GetSpeed() const
	{
		return speed;
	}
	FORCEINLINE void SetSpeed(const float _speed)
	{
		speed = _speed;
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
	MovementComponent(Actor* _owner, const float _speed = 10.0f,
		const Vector2f& _direction = Vector2f());

	MovementComponent(Actor* _owner, const MovementComponent& _other);

	virtual ~MovementComponent();

protected:
	virtual void Move(const float _deltaTime);
public:
	virtual void Tick(const float _deltaTime);
};

