#pragma once
#include "MovementComponent.h"
class PlayerMovementComponent :  public MovementComponent
{
	bool canMove;
	bool dodgeLaunch;
	float dodgeMultiplicater;
public:
	FORCEINLINE void SetCanMoveState(const bool _state)
	{
		canMove = _state;
	}
	virtual FORCEINLINE void ResetX()
	{
		if (!dodgeLaunch)direction.x = 0;
	}
	virtual FORCEINLINE void ResetY()
	{
		if (!dodgeLaunch)direction.y = 0;
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
	FORCEINLINE bool IsLaunch()
	{
		return dodgeLaunch;
	}
	FORCEINLINE void SetLaunchState(const bool _state)
	{
		dodgeLaunch = _state;

	}
	FORCEINLINE virtual Component* Clone(Actor* _owner) const
	{
		return new PlayerMovementComponent(_owner, *this);
	}


public:
	PlayerMovementComponent(Actor* _owner, const Vector2f& _velocity = Vector2f(),
		const Vector2f& _direction = Vector2f());
	PlayerMovementComponent(Actor* _owner, const PlayerMovementComponent& _other);

	virtual ~PlayerMovementComponent();

public:
	void Dash();
	virtual void Move(const float _deltaTime);
	virtual void ProcessInput(const Vector2f& _inputOffSet); 
};

