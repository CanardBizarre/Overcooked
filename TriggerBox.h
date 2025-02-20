#pragma once
#include "MeshActor.h"
#include "CollisionComponent.h"

class TriggerBox : public MeshActor
{
	function<void()> callback;
	CollisionComponent* collision;

public:
	FORCEINLINE function<void()> GetCallback() const
	{
		return callback;
	}


public:
	TriggerBox(Level* _level, function<void()> _callback, const RectangleShapeData& _data, const string& _name = "TriggerBox");
	TriggerBox(const TriggerBox& _other);
};

