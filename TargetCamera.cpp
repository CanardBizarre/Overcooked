#include "TargetCamera.h"

namespace Camera
{
	TargetCamera::TargetCamera(Level* _level, Actor* _target)
		: Actor(_level, "TargetCamera")
	{
		camera = CreateComponent<TargetCameraComponent>(_target);
	}

	TargetCamera::TargetCamera(const TargetCamera& _other)
		: Actor(_other)
	{
		camera = CreateComponent<TargetCameraComponent>(*_other.camera);
	}
	void TargetCamera::Tick(const float _deltaTime)
	{
		camera->ComputeCameraPos(_deltaTime);
	}
}







