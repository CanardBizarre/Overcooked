#include "HandSocket.h"

using namespace Layer;

HandSocket::HandSocket(Level* _level, const Vector2f& _pos, const float _handOffSet)
	:Actor(_level, "Hand", TransformData(Vector2f(0.0f, 0.0f), _pos, degrees(0.0f)))
{
	handOffSet = _handOffSet;
	collision = CreateComponent<CollisionComponent>();
	object = nullptr;
	InitCollision();
}

HandSocket::HandSocket(Level* _level, HandSocket* _other)
	:Actor(_level)
{
	handOffSet = _other->handOffSet;
	collision = CreateComponent<CollisionComponent>(*_other->collision);
	object = _other->object;
}

void HandSocket::InitCollision()
{
	collision->SetInformation("Hand", IS_ALL, CT_OVERLAP);
	vector<pair<string, CollisionType>> _reponses
	{
		{"Mesh", CT_OVERLAP},
	};
	collision->AddResponses(_reponses);
	SetLayerType(PLAYER);
}

void HandSocket::PickUp()
{
	if (object)
	{
		AddChild(object, AT_KEEP_RELATIVE);
	}
}

void HandSocket::DropObject()
{
	RemoveObject();
	// TODO Lacher l'objet
}

void HandSocket::ThrowObject()
{
	RemoveObject();
	// TODO Jeter l'objet
}

void HandSocket::Action()
{
	LOG(Warning, "Je suis Dedans");
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
}
