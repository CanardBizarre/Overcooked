#pragma once
#include "CameraComponent.h"

namespace Camera
{
	class TargetCameraComponent : public CameraComponent
	{
		class Actor* player;
		Vector2f targetPos;
		Vector2f refVel;
		Vector2f min;
		Vector2f max;

		float smoothTime;
		float maxRange;
		float minRange;

	public:
		FORCEINLINE void SetMaxAndMinCameraPosition(const Vector2f& _min, const Vector2f& _max)
		{
			min = _min;
			max = _max;
		}

	public:
		TargetCameraComponent(Actor* _owner, Actor* _target);
		TargetCameraComponent(Actor* _owner, const TargetCameraComponent& _other);

	private:
		Vector2f UpdateTargetPos();
		void UpdateCameraPosition(const float _delta);

	public:
		void ComputeCameraPos(const float _deltaTime);
		bool IsOutOfLimit();
	};
}



