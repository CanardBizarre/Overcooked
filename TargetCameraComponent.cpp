#include "TargetCameraComponent.h"
#include "Actor.h"
#include "Level.h"

Camera::TargetCameraComponent::TargetCameraComponent(Actor* _owner, Actor* _target)
	:CameraComponent(_owner)
{
	player = _target;
	smoothTime = 0.15f;
	refVel = Vector2f();
	maxRange = 200;
	minRange = -200;
}

Camera::TargetCameraComponent::TargetCameraComponent(Actor* _owner, const TargetCameraComponent& _other)
	:CameraComponent(_owner, _other)
{
	player = _other.player;
	smoothTime = _other.smoothTime;
	maxRange = _other.maxRange;
	minRange = _other.minRange;
}

Vector2f Camera::TargetCameraComponent::UpdateTargetPos()
{
	Vector2f _childPos = player->GetPosition();
	_childPos.x = clamp(_childPos.x, minRange, maxRange);
	_childPos.y = clamp(_childPos.y, minRange / 2.0f, maxRange / 2.0f);
	return _childPos;
}

void Camera::TargetCameraComponent::UpdateCameraPosition(const float _delta)
{
	const Vector2f& _tempVector = SmoothDamp(owner->GetPosition(), player->GetPosition() + targetPos,
		refVel, smoothTime, _delta, 200.0f);
	owner->SetPosition(_tempVector);
}

void Camera::TargetCameraComponent::ComputeCameraPos(const float _deltaTime)
{
	targetPos = UpdateTargetPos();
	if (!IsOutOfLimit())
	{
		UpdateCameraPosition(_deltaTime);
	}
}

bool Camera::TargetCameraComponent::IsOutOfLimit()
{
	if (owner->GetPosition().x - 500 < min.x || owner->GetPosition().x + 500 > max.x 
		|| owner->GetPosition().y - 250 < min.y || owner->GetPosition().y + 250 > max.y)
	{
		return true;
	}
	return false;
}



