#include "TestDummy.h"
#include "MeshActor.h"

TestDummy::TestDummy(Level* _level) 
	: RigidActor(_level, RectangleShapeData(Vector2f(40.0f,40.0f), "Props/PropsSpritesheet", PNG, false, IntRect(Vector2i(), Vector2i(124,124))))
{
	collision = CreateComponent<CollisionComponent>();
	move = CreateComponent<MovementComponent>();
	InitCollision();
}

TestDummy::TestDummy(const TestDummy& _other)
	:RigidActor(_other)
{
	collision = CreateComponent<CollisionComponent>(*_other.collision);
	move = CreateComponent<MovementComponent>(* _other.move);
}

void TestDummy::InitCollision()
{
	GetCollision()->SetInformation("Test", IS_ALL, CT_OVERLAP);
	vector<pair<string, CollisionType>> _reponses
	{
		{"Hand", CT_OVERLAP},
		//{"NONE", CT_NONE},
	};
	GetCollision()->AddResponses(_reponses);
	SetLayerType(PROP);
}

void TestDummy::Throw(const Vector2f& _direction)
{
	move->SetDirection(_direction);
}

void TestDummy::CollisionEnter(const CollisionData& _data)
{
}

void TestDummy::CollisionUpdate(const CollisionData& _data)
{
}

void TestDummy::CollisionExit(const CollisionData& _data)
{
}
