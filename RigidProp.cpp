#include "RigidProp.h"
#include "MovementComponent.h"


RigidProp::RigidProp(Level* _level, const RectangleShapeData& _data, const string& _name) : RigidActor(_level, _data, _name)
{
	GetCollision()->SetInformation("RigidProp", IS_ALL, CT_BLOCK);
	GetCollision()->AddResponses({{"PlayerPawn", CT_BLOCK}});
	SetLayerType(WORLD_STATIC);
}

RigidProp::RigidProp(const RigidProp& _other) : RigidActor(_other)
{
}

void RigidProp::CollisionEnter(const CollisionData& _data)
{
	if (_data.other->GetLayerType() == WORLD_STATIC)
	{
		if (_data.channelName == "playerPawn")
		{
			if (_data.response == CT_BLOCK)
			{
				MovementComponent* _movement = _data.other->GetComponent<MovementComponent>();
				_movement->SetSpeed(0.0f);
			}
		}
	}
}

void RigidProp::CollisionUpdate(const CollisionData& _data)
{
}

void RigidProp::CollisionExit(const CollisionData& _data)
{
	if (_data.other->GetLayerType() == WORLD_STATIC)
	{
		if (_data.channelName == "playerPawn")
		{
			if (_data.response == CT_BLOCK)
			{
				MovementComponent* _movement = _data.other->GetComponent<MovementComponent>();
				_movement->SetDirection(Vector2f());
				_movement->SetSpeed(0.0f);
			}
		}
	}
}
