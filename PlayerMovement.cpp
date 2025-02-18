#include "PlayerMovement.h"
#include "TimerManager.h"
#include "Actor.h"

PlayerMovementComponent::PlayerMovementComponent(Actor* _owner, const Vector2f& _velocity, const Vector2f& _direction)
	: MovementComponent(_owner, _velocity, _direction)
{
	canMove = true;
	dodgeLaunch = false;
	dodgeMultiplicater = 1.5;
}

PlayerMovementComponent::PlayerMovementComponent(Actor* _owner, const PlayerMovementComponent& _other)
	: MovementComponent(_owner, _other)
{
	canMove = _other.canMove;
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
		const Vector2f& _offset = Vector2f(direction.x * velocity.x * _deltaTime * dodgeMultiplicater, direction.y * velocity.y * _deltaTime* dodgeMultiplicater );
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
