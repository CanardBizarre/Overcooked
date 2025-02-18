#include "PlayerMovement.h"
#include "TimerManager.h"
#include "Actor.h"

PlayerMovementComponent::PlayerMovementComponent(Actor* _owner, const float _speed, const Vector2f& _direction)
	: MovementComponent(_owner, _speed, _direction)
{
	canMove = true;
	dodgeLaunch = false;
	dodgeMultiplicater = 1.5f;
}

PlayerMovementComponent::PlayerMovementComponent(Actor* _owner, const PlayerMovementComponent& _other)
	: MovementComponent(_owner)
{
	canMove = _other.canMove;
	speed = _other.speed;
	direction = _other.direction;
}

PlayerMovementComponent::~PlayerMovementComponent()
{
}

void PlayerMovementComponent::Dash()
{
	if (!dodgeLaunch && !IsDirectionNull())
	{
		SetLaunchState(true);
		SetCanMoveState(false);
		new Timer([&]()
			{
				SetLaunchState(false);
				SetCanMoveState(true);
				ResetX();
				ResetY();
			}, seconds(0.7f), true, false);
	}
}

void PlayerMovementComponent::Move(const float _deltaTime)
{
	if (canMove)
	{
		Super::Move(_deltaTime);
	}
	if(dodgeLaunch)
	{
		const Vector2f& _offset = direction * speed * _deltaTime * dodgeMultiplicater;
		owner->Move(_offset);
		return;
	}
}

void PlayerMovementComponent::ProcessInput(const Vector2f& _inputOffSet)
{
	direction += _inputOffSet;
	
	direction.x = direction.x < -1.0f ? -1.0f : direction.x;
	direction.x = direction.x > 1.0f ? 1.0f : direction.x;

	direction.y = direction.y < -1.0f ? -1.0f : direction.y;
	direction.y = direction.y > 1.0f ? 1.0f : direction.y;

	if (!IsVector2fNull(direction))
	{
		direction = direction.normalized();
	}

}
