#include "HandSocket.h"
#include "Bounds.h"
#include "TestDummy.h"
using namespace Layer;

HandSocket::HandSocket(Level* _level, const Vector2f& _pos, const float _handOffSet)
	:Actor(_level, "Hand", 
		TransformData(Vector2f(20.0f, 20.0f), _pos, degrees(0.0f)))
{
	handOffSet = _handOffSet;
	collision = CreateComponent<CollisionComponent>();
	isNearCounter = false;
	object = nullptr;
	InitCollision();
}

HandSocket::HandSocket(Level* _level, HandSocket* _other)
	:Actor(_level)
{
	handOffSet = _other->handOffSet;
	isNearCounter = _other->isNearCounter;
	collision = CreateComponent<CollisionComponent>(*_other->collision);
	object = _other->object;
}


void HandSocket::InitCollision()
{
	collision->SetInformation("Hand", IS_ALL, CT_OVERLAP);
	vector<pair<string, CollisionType>> _reponses
	{
		{"Test", CT_OVERLAP},
	};
	collision->AddResponses(_reponses);
	SetLayerType(PLAYER);

}

void HandSocket::PickUp()
{
	if (object)
	{
		AddChild(object, AT_SNAP_TO_TARGET);
	}
}

void HandSocket::DropObject()
{
	RemoveObject();
	// TODO Lacher l'objet
}

void HandSocket::ThrowObject()
{
	Actor* _current = RemoveObject();
	if (TestDummy* _dummy= Cast<TestDummy>(_current))
	{
		_dummy->Throw(GetParent()->GetForwardVector());
	}
	// TODO Jeter l'objet
}

void HandSocket::Action()
{
	if (IsCarryingAnObject())
	{
		if (isNearCounter) return DropObject();
		ThrowObject();
	}
	else if (object)
	{
		PickUp();
	}
}

void HandSocket::CollisionEnter(const CollisionData& _data)
{
	if (_data.other->GetLayerType() == PROP)
	{
		if (_data.channelName == "Test")
		{
			object = _data.other;
		}
		if (_data.channelName == "Counter")
		{
			isNearCounter = true;
		}
	}
}

void HandSocket::CollisionUpdate(const CollisionData& _data)
{

}

void HandSocket::CollisionExit(const CollisionData& _data)
{
	if (_data.other->GetLayerType() == PROP)
	{
		// TODO changer le channel name
		if (_data.channelName == "Test")
		{
			object = nullptr;
		}
		if (_data.channelName == "Counter")
		{
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
	SetPosition(_position + handOffSet * _foward);

	const FloatRect& _rect = FloatRect(GetPosition(), { 20.0f, 20.0f });
	collision->GetBounds()->SetBoundsData(new RectangleBoundsData(_rect, Angle()));
}
