#include "MovementComponent.h"
#include "Actor.h"

MovementComponent::MovementComponent(Actor* _owner, const float _speed,
	const Vector2f& _direction)
	: Component(_owner)
{
	speed = _speed;
	direction = _direction;
}

MovementComponent::MovementComponent(Actor* _owner, const MovementComponent& _other)
	: Component(_owner)
{
	speed = _other.speed;
	direction = _other.direction;
}

MovementComponent::~MovementComponent()
{
}

void MovementComponent::Move(const float _deltaTime)
{
	const Vector2f& _offset = direction * speed * _deltaTime;
	owner->Move(_offset);
}

void MovementComponent::Tick(const float _deltaTime)
{
	Move(_deltaTime);
}
