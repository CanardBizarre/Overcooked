#pragma once
#include "MovementComponent.h"

class CarMovementComponent : public MovementComponent
{

public:
	virtual FORCEINLINE void ResetX()
	{
		direction.x = 0;
	}
	virtual FORCEINLINE void ResetY()
	{
		direction.y = 0;
	}
	FORCEINLINE bool IsAxisNormalise(const float _axis)
	{
		return _axis <= 1.0f && _axis >= -1.0f;
	}
	FORCEINLINE bool IsVector2fNormalise(const Vector2f& _vectorDirection)
	{
		return IsAxisNormalise(_vectorDirection.x) && IsAxisNormalise(_vectorDirection.y);
	}
	FORCEINLINE bool IsVector2fNull(const Vector2f& _vectorDirection)
	{
		return _vectorDirection.x == 0.0f && _vectorDirection.y == 0.0f;
	}
	FORCEINLINE virtual Component* Clone(Actor* _owner) const
	{
		return new CarMovementComponent(_owner, *this);
	}

public:
	CarMovementComponent(Actor* _owner, const Vector2f& _velocity = Vector2f(),
		const Vector2f& _direction = Vector2f());
	CarMovementComponent(Actor* _owner, const CarMovementComponent& _other);

	virtual ~CarMovementComponent();

public:
	void ProcessInput(const Vector2f& _inputOffSet);
};

