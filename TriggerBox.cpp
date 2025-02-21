#include "TriggerBox.h"

TriggerBox::TriggerBox(Level* _level, function<void()> _callback, const RectangleShapeData& _data, const string& _name) : MeshActor(_level, _data, _name)
{
	mesh->SetOriginAtMiddle();
	callback = _callback;
	collision = CreateComponent<CollisionComponent>();
	collision->SetInformation("TriggerBox", IS_ALL, CT_OVERLAP);
	collision->AddResponses(
		{
			{ "Player", CT_OVERLAP },
		});
	SetLayerType(PLAYER);
	SetLayerType(WORLD_STATIC);
	SetZOrder(0);
}

TriggerBox::TriggerBox(const TriggerBox& _other) : MeshActor(_other)
{
	callback = _other.callback;
	collision = CreateComponent<CollisionComponent>(*_other.collision);
}
