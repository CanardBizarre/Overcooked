#include "TargetCameraComponent.h"
#include "Actor.h"
#include "Level.h"

Camera::TargetCameraComponent::TargetCameraComponent(Actor* _owner, Actor* _target)
	:CameraComponent(_owner)
{
	player = _target;
	smoothTime = 0.15f;
	mousePos = Vector2f();
	refVel = Vector2f();
	maxRange = 200;
	minRange = -200;
}

Camera::TargetCameraComponent::TargetCameraComponent(Actor* _owner, const TargetCameraComponent& _other)
	:CameraComponent(_owner, _other)
{
	player = _other.player;
	mousePos = _other.mousePos;
	smoothTime = _other.smoothTime;
	maxRange = _other.maxRange;
	minRange = _other.minRange;
}

Vector2f Camera::TargetCameraComponent::UpdateTargetPos()
{
	const Vector2f& _childPos = player->GetPosition();
	Vector2f _ret = Vector2f(mousePos - _childPos) / 2.5f;
	_ret.x = clamp(_ret.x, minRange, maxRange);
	_ret.y = clamp(_ret.y, minRange / 2.0f, maxRange / 2.0f);
	return _ret;
}

void Camera::TargetCameraComponent::UpdateCameraPosition(const float _delta)
{
	const Vector2f& _tempVector = SmoothDamp(owner->GetPosition(), player->GetPosition() + targetPos,
		refVel, smoothTime, _delta);
	owner->SetPosition(_tempVector);
}

void Camera::TargetCameraComponent::ComputeCameraPos(const float _deltaTime)
{
	CaptureMousePos(player->GetLevel()->GetPixelTooCoords());
	targetPos = UpdateTargetPos();
	UpdateCameraPosition(_deltaTime);
}


