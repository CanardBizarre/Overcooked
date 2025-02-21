#pragma once
#include "Actor.h"
#include "TargetCameraComponent.h"

using namespace Camera;
namespace Camera
{
	class TargetCamera : public Actor
	{
		TargetCameraComponent* camera;

	public:
		FORCEINLINE CameraComponent* GetCamera() const
		{
			return camera;
		}
		FORCEINLINE void SetViewport(const FloatRect& _rect)
		{
			camera->SetViewport(_rect);
		}
		FORCEINLINE virtual void SetPosition(const Vector2f& _center) override
		{
			Super::SetPosition(_center);
			camera->SetCenter(_center);
		}
		FORCEINLINE virtual void SetRotation(const Angle& _angle) override
		{
			Super::SetRotation(_angle);
			camera->SetRotation(_angle);
		}
		FORCEINLINE virtual void SetScale(const Vector2f& _scale) override
		{
			Super::SetScale(_scale);
			camera->SetSize(_scale);
		}
		FORCEINLINE void SetScissor(const FloatRect& _rect)
		{
			camera->SetScissor(_rect);
		}
		FORCEINLINE virtual void Move(const Vector2f& _offset) override
		{
			Super::Move(_offset);
			camera->Move(_offset);
		}
		FORCEINLINE virtual void Rotate(const Angle& _angle) override
		{
			Super::Rotate(_angle);
			camera->Rotate(_angle);
		}
		FORCEINLINE void Zoom(const float _factor)
		{
			camera->Zoom(_factor);
		}
		FORCEINLINE TargetCameraComponent* GetCamera()
		{
			return camera;
		}

	public:
		TargetCamera(Level* _level, Actor* _target);
		TargetCamera(const TargetCamera& _other);
	public:
		virtual void Tick(const float _deltaTime) override;
	};
}




