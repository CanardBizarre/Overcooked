#include "MovementComponent.h"
#include "Actor.h"

MovementComponent::MovementComponent(Actor* _owner, const Vector2f& _velocity,
	const Vector2f& _direction)
	: Component(_owner)
{
	velocity = _velocity;
	direction = _direction;
}

MovementComponent::MovementComponent(Actor* _owner, const MovementComponent& _other)
	: Component(_owner, _other)
{
	velocity = _other.velocity;
	direction = _other.direction;
}

MovementComponent::~MovementComponent()
{
}

void MovementComponent::Move(const float _deltaTime)
{
	const Vector2f& _offset = { direction.x * velocity.x * _deltaTime, direction.y * velocity.y * _deltaTime };
	owner->Move(_offset);
}

void MovementComponent::Tick(const float _deltaTime)
{
	Move(_deltaTime);
}
