#pragma once
#include "CameraComponent.h"

namespace Camera
{
	class TargetCameraComponent : public CameraComponent
	{
		class Actor* player;
		Vector2f mousePos;
		Vector2f targetPos;
		Vector2f refVel;
		float smoothTime;

		float maxRange;
		float minRange;

	public:
		FORCEINLINE void CaptureMousePos(const Vector2f& _mousePos)
		{
			mousePos = _mousePos;
		}

	public:
		TargetCameraComponent(Actor* _owner, Actor* _target);
		TargetCameraComponent(Actor* _owner, const TargetCameraComponent& _other);

	private:
		Vector2f UpdateTargetPos();
		void UpdateCameraPosition(const float _delta);

	public:
		void ComputeCameraPos(const float _deltaTime);
	};
}



