#include "TestDummy.h"

TestDummy::TestDummy(Level* _level)
	:MeshActor(_level, RectangleShapeData(Vector2f(20.0f,20.0f), "Ball", PNG))
{
	collision = CreateComponent<CollisionComponent>();
	InitCollision();
}

TestDummy::TestDummy(const TestDummy& _other)
	:MeshActor(_other)
{
	collision = CreateComponent<CollisionComponent>(*_other.collision);
}

void TestDummy::InitCollision()
{
	collision->SetInformation("Test", IS_ALL, CT_OVERLAP);
	vector<pair<string, CollisionType>> _reponses
	{
		{"Hand", CT_OVERLAP},
		{"NONE", CT_NONE},
	};
	collision->AddResponses(_reponses);
	SetLayerType(PROP);
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
