#include "PlayerMovement.h"
#include "TimerManager.h"
#include "Actor.h"
#include "LevelManager.h"
#include "DashEffect.h"


PlayerMovementComponent::PlayerMovementComponent(Actor* _owner, const Vector2f& _velocity, const Vector2f& _direction)
	: MovementComponent(_owner, _velocity, _direction)
{
	canMove = true;
	dodgeLaunch = false;
	dodgeMultiplicater = 2.0f;
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
		SpawnDashEffect();
		SetLaunchState(true);
		SetCanMoveState(false);
		new Timer([&]()
			{
				SetLaunchState(false);
				SetCanMoveState(true);
				ResetX();
				ResetY();
			}, seconds(0.2f), true, false);
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

void PlayerMovementComponent::SpawnDashEffect()
{
	Level* _level = M_LEVEL.GetCurrentLevel();

	DashEffect* _effect = _level->SpawnActor<DashEffect>(RectangleShapeData(Vector2f(100,100), "Effects/DashEffect"), "dash");
	_effect->SetPosition(GetOwner()->GetPosition());
	_effect->SetRotation(GetOwner()->GetRotation());
}

