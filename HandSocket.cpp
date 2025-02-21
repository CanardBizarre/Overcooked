#include "HandSocket.h"
#include "Bounds.h"
#include "TestDummy.h"
#include "Actor.h"
#include "RigidBodyComponent.h"
#include "MovementComponent.h"
#include "Seizable.h"
#include "Level.h"

using namespace Layer;

HandSocket::HandSocket(Level* _level, const Vector2f& _pos, const float _handOffSet)
	:Actor(_level, "Hand", TransformData(Vector2f(20.0f, 20.0f), _pos, degrees(0.0f)))
{
	handOffSet = _handOffSet;
	collision = CreateComponent<CollisionComponent>();
	mesh = CreateComponent<MeshComponent>(RectangleShapeData(Vector2f(40.0f, 40.0f),
		"Characters/Hands/spritesheet_opened", PNG, false, IntRect(Vector2i(), Vector2i(124, 124))));
	isNearCounter = false;
	object = nullptr;

	InitCollision();
}

HandSocket::HandSocket(Level* _level, HandSocket* _other)
	:Actor(_level)
{
	handOffSet = _other->handOffSet;
	isNearCounter = _other->isNearCounter;
	collision = CreateComponent<CollisionComponent>(_other->collision);
	mesh = CreateComponent<MeshComponent>(*_other->mesh);
	object = _other->object;
}


void HandSocket::InitCollision()
{
	collision->SetInformation("Hand", IS_ALL, CT_OVERLAP);
	vector<pair<string, CollisionType>> _reponses
	{
		{"Seizable", CT_OVERLAP},
		{"KitchenBlock", CT_OVERLAP},
	};
	collision->AddResponses(_reponses);
	SetLayerType(PLAYER);
}

void HandSocket::PickUp()
{
	if (object)
	{
		AddChild(object, AT_SNAP_TO_TARGET);

		if (isNearCounter) nearestBlock->ExitAction(object);
	}

}

void HandSocket::DropObject()
{
	if (!object) return;

	if (!nearestBlock->EnterAction(object, isDish)) return;

	RemoveObject();
	isNearCounter = false;
}

void HandSocket::ThrowObject()
{
	Actor* _current = RemoveObject();
	if (Seizable* _dummy = Cast<Seizable>(_current))
	{
		_dummy->Throw(GetParent()->GetForwardVector());
	}
	RemoveObject();
	// TODO Jeter l'objet
}

void HandSocket::HandAction()
{
	if (IsCarryingAnObject())
	{
		if (isNearCounter) return DropObject();
		ThrowObject();
	}
	else if (!IsCarryingAnObject() && object)
	{
		PickUp();
	}
	else if (!IsCarryingAnObject() && !object)
	{
		if (isNearCounter) nearestBlock->ActionWithoutObject(this);
	}
}

void HandSocket::CollisionEnter(const CollisionData& _data)
{
	/*if (_data.other->GetLayerType() == PROP)
	{
		if (_data.channelName == "Test")
		{
			object = _data.other;
		}
		if (_data.channelName == "KitchenBlock")
		{
			nearestBlock = Cast<KitchenBlock>(_data.other);
			isNearCounter = true;
		}

	}*/
}

void HandSocket::CollisionUpdate(const CollisionData& _data)
{
	if (_data.other->GetLayerType() == PROP)
	{
		if (_data.channelName == "Seizable")
		{
			object = _data.other;
			isDish = false;
		}
		else if (_data.channelName == "Dish")
		{
			object = _data.other;
			isDish = true;
		}
		else if (_data.channelName == "KitchenBlock")
		{
			nearestBlock = Cast<KitchenBlock>(_data.other);
			isNearCounter = true;
		}
	}
}

void HandSocket::CollisionExit(const CollisionData& _data)
{
	if (_data.other->GetLayerType() == PROP)
	{
		// TODO changer le channel name
		if (_data.channelName == "Seizable")
		{
			object = nullptr;
		}
		if (_data.channelName == "KitchenBlock")
		{
			nearestBlock = nullptr;
			isNearCounter = false;
		}
	}
}

void HandSocket::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);
	Actor* _parent = GetParent();
	const Vector2f& _foward = _parent->GetForwardVector();
	const Vector2f& _position = _parent->GetPosition();
	const Vector2f& _origine = _parent->GetOrigin();
	SetPosition(_position + handOffSet * _foward);

	const FloatRect& _rect = FloatRect(GetPosition(), { 20.0f, 20.0f });
	collision->GetBounds()->SetBoundsData(new RectangleBoundsData(_rect, { 0, _origine.y }, Angle()));
}

void HandSocket::Construct()
{
	Super::Construct();
	mesh->SetOriginAtMiddle();
	SetZOrder(21);

}

void HandSocket::SetZOrder(const int _zOrder)
{
	Super::SetZOrder(_zOrder);

	GetLevel()->GetCameraManager().SetZOrder(mesh->GetRenderMeshToken(), zOrder);
}
