#include "CarMovementComponent.h"

CarMovementComponent::CarMovementComponent(Actor* _owner, const Vector2f& _velocity, const Vector2f& _direction) : MovementComponent(_owner, _velocity, _direction)
{
}

CarMovementComponent::CarMovementComponent(Actor* _owner, const CarMovementComponent& _other) : MovementComponent(_owner, _other)
{
}

CarMovementComponent::~CarMovementComponent()
{
}

void CarMovementComponent::ProcessInput(const Vector2f& _inputOffSet)
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
